class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // [start, end, weight, original_index]
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting position
        sort(a.begin(), a.end());

        // next[i] = first interval whose start > a[i].end
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i][k]:
        // best answer using intervals from i onward,
        // with at most k intervals available.
        vector<vector<State>> dp(n + 1, vector<State>(5));

        auto better = [](const State& x, const State& y) {
            if (x.score != y.score)
                return x.score > y.score;

            return x.ids < y.ids;
        };

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip current interval
                State skip = dp[i + 1][k];

                // Option 2: take current interval
                State take;
                take.score = a[i][2];
                take.ids.push_back((int)a[i][3]);

                if (next[i] < n) {
                    take.score += dp[next[i]][k - 1].score;

                    for (int id : dp[next[i]][k - 1].ids)
                        take.ids.push_back(id);
                }

                // Sort indices because lexicographical comparison
                // is based on the original indices.
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].ids;
    }
};

    

