class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nextBuy = 0;
        int nextHold = 0;
        int next2Buy = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {

            int buy = max(-prices[i] + nextHold, nextBuy);

            int hold = max(prices[i] + next2Buy, nextHold);

            next2Buy = nextBuy;
            nextBuy = buy;
            nextHold = hold;
        }

        return nextBuy;
    }
};