class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =  prices.size();
        int aheadnotbuy,aheadbuy,curbuy,curnotbuy;
        aheadnotbuy = aheadbuy = 0;
        for(int idx = n-1; idx >=0 ; idx--){
            curnotbuy = max(prices[idx]+aheadbuy,aheadnotbuy);
            curbuy = max(-prices[idx]+aheadnotbuy,aheadbuy);
            aheadbuy = curbuy;
            aheadnotbuy = curnotbuy;
        }
        return aheadbuy;
    }
};