class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> next(4, 0);
        vector<int> cur(4, 0);

        for(int idx = n - 1; idx >= 0; idx--) {

            cur[0] = max(-prices[idx] + next[1],
                         next[0]);

            cur[1] = max(prices[idx] + next[2],
                         next[1]);

            cur[2] = max(-prices[idx] + next[3],
                         next[2]);

            cur[3] = max(prices[idx],
                         next[3]);

            next = cur;
        }

        return next[0];
    }
};