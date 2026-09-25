class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        const int INF = 1e9;

        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int coin : coins) {
            for (int t = coin; t <= amount; t++) {
                dp[t] = min(dp[t], 1 + dp[t - coin]);
            }
        }

        return dp[amount] >= INF ? -1 : dp[amount];
    }
};