class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> dp;

    bool solve(int pos, int jump, vector<int>& stones) {

        // Reached the last stone
        if (pos == stones.size() - 1)
            return true;

        if (dp[pos][jump] != -1)
            return dp[pos][jump];

        for (int nextJump = jump - 1;
             nextJump <= jump + 1;
             nextJump++) {

            if (nextJump <= 0)
                continue;

            int nextPos = stones[pos] + nextJump;

            if (mp.count(nextPos)) {

                int nextIndex = mp[nextPos];

                if (solve(nextIndex, nextJump, stones))
                    return dp[pos][jump] = 1;
            }
        }

        return dp[pos][jump] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        mp.clear();

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        dp.assign(n, vector<int>(n + 1, -1));

        // First jump must be 1
        if (!mp.count(1))
            return false;

        return solve(mp[1], 1, stones);
    }
};