class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m);

        for (int j = 0; j < m; j++)
            prev[j] = matrix[0][j];

        for (int i = 1; i < n; i++) {

            vector<int> cur(m, 0);

            for (int j = 0; j < m; j++) {

                int up = matrix[i][j] + prev[j];

                int leftDiag = 1e9;
                if (j > 0)
                    leftDiag = matrix[i][j] + prev[j - 1];

                int rightDiag = 1e9;
                if (j + 1 < m)
                    rightDiag = matrix[i][j] + prev[j + 1];

                cur[j] = min(up, min(leftDiag, rightDiag));
            }

            prev = cur;
        }

        return *min_element(prev.begin(), prev.end());
    }
};