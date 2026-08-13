class Solution {
    void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int row,
             int col, int color, int lastcol) {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        static const int delrow[4] = {-1, 0, 1, 0};
        static const int delcol[4] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == lastcol && ans[nrow][ncol] != color) {
                dfs(ans, image, nrow, ncol, color, lastcol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int lastcol = image[sr][sc];
        if (lastcol == color)
            return image;
        vector<vector<int>> ans = image;
        dfs(ans, image, sr, sc, color, lastcol);
        return ans;
    }
};