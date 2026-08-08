class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[j] = position in word1 where word2[j]
        // can be matched when matching from right.
        vector<int> suf(m, -1);

        int p = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (p >= 0 && word1[p] != word2[j])
                p--;

            if (p < 0)
                break;

            suf[j] = p;
            p--;
        }

        vector<int> ans;

        int j = 0;
        bool used = false;

        for (int i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use the one allowed mismatch
            else if (!used &&
                     (j == m - 1 ||
                      (suf[j + 1] != -1 && suf[j + 1] > i))) {

                ans.push_back(i);
                j++;
                used = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};