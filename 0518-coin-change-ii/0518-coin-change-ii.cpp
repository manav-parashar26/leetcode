class Solution {
public:
    int change(int amount, vector<int>& coins) {

        const int LIMIT = INT_MAX;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int t = coin; t <= amount; t++) {

                if (dp[t - coin] > LIMIT - dp[t])
                    dp[t] = LIMIT;
                else
                    dp[t] += dp[t - coin];
            }
        }

        return dp[amount];
    }
};