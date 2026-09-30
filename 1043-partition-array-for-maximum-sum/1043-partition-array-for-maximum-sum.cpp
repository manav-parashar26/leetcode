class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i = n-1 ; i >= 0 ;i--){
            int len = 0; 
            int maxi = INT_MIN;
            int ansmaxi = INT_MIN;
            for(int j = i; j < min(i+k,n) ;j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = len * maxi + dp[j+1];
                ansmaxi = max(ansmaxi,sum);
            }
            dp[i] = ansmaxi;
        }
        return dp[0];
    }
};