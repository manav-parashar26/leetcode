class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prev(m, vector<int>(m, -1));

        prev[0][m - 1] = grid[0][0] + grid[0][m - 1];

        if (m == 1)
            prev[0][0] = grid[0][0];

        for (int row = 1; row < n; row++) {

            vector<vector<int>> cur(m, vector<int>(m, -1));

            for (int col1 = 0; col1 < m; col1++) {

                for (int col2 = 0; col2 < m; col2++) {

                    int cherries = grid[row][col1];

                    if (col1 != col2)
                        cherries += grid[row][col2];

                    for (int d1 = -1; d1 <= 1; d1++) {

                        for (int d2 = -1; d2 <= 1; d2++) {

                            int p1 = col1 + d1;
                            int p2 = col2 + d2;

                            if (p1 < 0 || p1 >= m || p2 < 0 || p2 >= m)
                                continue;

                            if (prev[p1][p2] == -1)
                                continue;

                            cur[col1][col2] =
                                max(cur[col1][col2], prev[p1][p2] + cherries);
                        }
                    }
                }
            }

            prev = cur;
        }

        int ans = 0;

        for (int col1 = 0; col1 < m; col1++) {
            for (int col2 = 0; col2 < m; col2++) {
                ans = max(ans, prev[col1][col2]);
            }
        }

        return ans;
    }
};