class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        // Impossible cases
        if(abs(target) > total)
            return 0;

        if((total + target) % 2 != 0)
            return 0;

        int sum = (total + target) / 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for(int x : nums) {
            for(int s = sum; s >= x; s--) {
                dp[s] += dp[s - x];
            }
        }

        return dp[sum];
    }
};