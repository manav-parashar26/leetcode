class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< m ;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] =1;
                }else vis[i][j] = 0;
            }
        }
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        while(!q.empty()){
            auto [pos,step] = q.front();q.pop();
            auto [r,c] = pos;
            dist[r][c] = step;
            for(int i = 0;i < 4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},step + 1});
                }
            }
        }
        return dist;
    }
};