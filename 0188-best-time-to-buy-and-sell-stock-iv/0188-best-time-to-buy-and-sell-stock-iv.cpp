class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        vector<int> dp(2 * k, INT_MIN);

        for(int price : prices) {

            dp[0] = max(dp[0], -price);

            for(int i = 1; i < 2 * k; i++) {

                if(i & 1) {
                    // Sell
                    dp[i] = max(dp[i], dp[i - 1] + price);
                }
                else {
                    // Buy
                    dp[i] = max(dp[i], dp[i - 1] - price);
                }
            }
        }

        return max(0, dp[2 * k - 1]);
    }
};