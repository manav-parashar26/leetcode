class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int len = n + m - 1;

        if (len % 2 == 1)
            return false;

        if (grid[0][0] == ')' || grid[n-1][m-1] == '(')
            return false;

        vector<vector<bool>> prev(m, vector<bool>(len + 1, false));

        for (int i = 0; i < n; i++) {

            vector<vector<bool>> cur(
                m, vector<bool>(len + 1, false)
            );

            for (int j = 0; j < m; j++) {

                // Starting cell
                if (i == 0 && j == 0) {
                    cur[0][1] = true;
                    continue;
                }

                for (int bal = 0; bal <= len; bal++) {

                    bool possible = false;

                    // From above
                    if (i > 0)
                        possible |= prev[j][bal];

                    // From left
                    if (j > 0)
                        possible |= cur[j - 1][bal];

                    if (!possible)
                        continue;

                    int newBal;

                    if (grid[i][j] == '(')
                        newBal = bal + 1;
                    else
                        newBal = bal - 1;

                    if (newBal >= 0 && newBal <= len)
                        cur[j][newBal] = true;
                }
            }

            prev = move(cur);
        }

        return prev[m - 1][0];
    }
};