class Solution {
public:

    void generate(vector<int>& arr,
                  vector<vector<long long>>& sums) {

        int n = arr.size();

        for (int mask = 0; mask < (1 << n); mask++) {

            long long sum = 0;
            int count = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    sum += arr[i];
                    count++;
                }
            }

            sums[count].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {

        int N = nums.size();
        int n = N / 2;

        vector<int> left(nums.begin(),
                         nums.begin() + n);

        vector<int> right(nums.begin() + n,
                          nums.end());

        vector<vector<long long>> leftSums(n + 1);
        vector<vector<long long>> rightSums(n + 1);

        // Generate all subset sums
        generate(left, leftSums);
        generate(right, rightSums);

        // Sort right-side sums for binary search
        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(),
                 rightSums[i].end());
        }

        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        long long ans = LLONG_MAX;

        // k = number of elements selected from left
        for (int k = 0; k <= n; k++) {

            int need = n - k;

            for (long long leftSum : leftSums[k]) {

                long long target =
                    total / 2.0 - leftSum;

                auto it = lower_bound(
                    rightSums[need].begin(),
                    rightSums[need].end(),
                    target
                );

                // Candidate >= target
                if (it != rightSums[need].end()) {

                    long long selected =
                        leftSum + *it;

                    ans = min(
                        ans,
                        llabs(2 * selected - total)
                    );
                }

                // Candidate < target
                if (it != rightSums[need].begin()) {

                    --it;

                    long long selected =
                        leftSum + *it;

                    ans = min(
                        ans,
                        llabs(2 * selected - total)
                    );
                }
            }
        }

        return (int)ans;
    }
};