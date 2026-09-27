class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);

        prev[0] = true;

        // Empty string matched by '*' only
        for(int j = 1; j <= m; j++) {
            prev[j] = prev[j-1] && p[j-1] == '*';
        }

        for(int i = 1; i <= n; i++) {

            cur[0] = false;

            for(int j = 1; j <= m; j++) {

                if(s[i-1] == p[j-1] || p[j-1] == '?') {

                    cur[j] = prev[j-1];

                }
                else if(p[j-1] == '*') {

                    cur[j] = cur[j-1] || prev[j];

                }
                else {

                    cur[j] = false;
                }
            }

            prev = cur;
        }

        return prev[m];
    }
};