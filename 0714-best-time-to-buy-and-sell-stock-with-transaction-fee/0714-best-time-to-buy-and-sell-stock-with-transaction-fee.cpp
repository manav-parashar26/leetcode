class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int canBuy = 0;
        int holding = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {

            int nextCanBuy = canBuy;
            int nextHolding = holding;

            canBuy = max(-prices[i] + nextHolding, nextCanBuy);

            holding = max(prices[i] - fee + nextCanBuy, nextHolding);
        }

        return canBuy;
    }
};