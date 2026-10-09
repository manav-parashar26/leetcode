class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0, open = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                open++;
            }
            else {
                if(i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    cnt++;
                }

                if(open > 0) {
                    open--;
                }
                else {
                    cnt++;
                }
            }
        }

        return cnt + 2 * open;
    }
};