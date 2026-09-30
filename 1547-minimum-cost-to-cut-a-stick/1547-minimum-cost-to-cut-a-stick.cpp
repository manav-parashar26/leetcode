class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c,vector<int>(c,0));
        for(int i = c-2 ; i >= 1 ; i--){
            for(int j = i ; j <= c-2 ; j++){
                int mini = INT_MAX;
                for(int idx = i ; idx  <= j ;idx++){
                    int cost = cuts[j+1]-cuts[i-1]+dp[i][idx-1]+dp[idx+1][j];
                    mini = min(mini ,cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c-2];
    }
};  