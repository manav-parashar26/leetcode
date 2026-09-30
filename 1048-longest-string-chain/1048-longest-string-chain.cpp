class Solution {
public:
    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1)
            return false;

        int idx1 = 0;
        int idx2 = 0;

        while (idx1 != s1.size()) {
            if (s1[idx1] == s2[idx2]) {
                idx1++;
                idx2++;
            } else {
                idx1++;
            }
        }

        if (idx2 == s2.size())
            return true;

        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        vector<int> dp(n, 1);

        int maxi = 1;

        sort(words.begin(), words.end(),
             [](const string& s1, const string& s2) {
                 return s1.size() < s2.size();
             });

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (check(words[i], words[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};