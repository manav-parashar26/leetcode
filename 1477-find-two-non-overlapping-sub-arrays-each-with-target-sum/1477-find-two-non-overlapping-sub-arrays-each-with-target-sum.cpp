class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int ans = INF;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (i > 0)
                best[i] = best[i - 1];

            if (mp.count(sum - target)) {
                int j = mp[sum - target];

                int len = i - j;
                if (j >= 0 && best[j] != INF) {
                    ans = min(ans, len + best[j]);
                }

                best[i] = min(best[i], len);
            }

            mp[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};