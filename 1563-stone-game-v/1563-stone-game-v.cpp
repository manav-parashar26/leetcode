class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> memo;

    int rangeSum(int i, int j) { // inclusive sum [i, j]
        return prefix[j + 1] - prefix[i];
    }

    int solve(int i, int j) {
        if (i == j) return 0;               // single stone, nothing more to gain
        if (memo[i][j] != -1) return memo[i][j];

        int best = 0;
        for (int k = i; k < j; k++) {
            int leftSum  = rangeSum(i, k);
            int rightSum = rangeSum(k + 1, j);

            if (leftSum < rightSum)
                best = max(best, leftSum + solve(i, k));
            else if (rightSum < leftSum)
                best = max(best, rightSum + solve(k + 1, j));
            else // tie — Alice keeps whichever half helps more
                best = max({best, leftSum + solve(i, k), rightSum + solve(k + 1, j)});
        }
        return memo[i][j] = best;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stoneValue[i];

        memo.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
};