class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sum
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // If we take all stones
        int dp = stones[n - 1];

        // Work backwards
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};