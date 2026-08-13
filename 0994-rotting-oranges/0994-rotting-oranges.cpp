class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntfre = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) cntfre++;
            }
        }

        int tm = 0;
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,-1,0,1};
        int cnt = 0;

        while(!q.empty()){
            auto [pos, t] = q.front(); q.pop();
            auto [r, c] = pos;
            tm = max(tm, t);

            for(int i = 0; i < 4; i++){
                int nrow = r + row[i];
                int ncol = c + col[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        return (cnt != cntfre) ? -1 : tm;
    }
};