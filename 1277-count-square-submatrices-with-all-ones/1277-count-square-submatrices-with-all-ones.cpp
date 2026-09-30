class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> dp(m, 0);
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            
            int diagonal = 0;
            
            for(int j = 0; j < m; j++){
                
                int temp = dp[j];
                
                if(matrix[i][j] == 1){
                    
                    if(i == 0 || j == 0){
                        dp[j] = 1;
                    }
                    else{
                        dp[j] = min(dp[j], min(dp[j-1], diagonal)) + 1;
                    }
                    
                    sum += dp[j];
                }
                else{
                    dp[j] = 0;
                }
                
                diagonal = temp;
            }
        }
        
        return sum;
    }
};