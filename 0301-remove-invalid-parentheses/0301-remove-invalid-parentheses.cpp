class Solution {
public:
    vector<string> ans;

    void removeInvalid(string s, int start, int lastRemove, char open,
                       char close) {

        int balance = 0;

        for (int i = start; i < s.size(); i++) {

            if (s[i] == open)
                balance++;

            else if (s[i] == close)
                balance--;

            if (balance >= 0)
                continue;

            // Remove one ')' from this invalid region
            for (int j = lastRemove; j <= i; j++) {

                if (s[j] == close && (j == lastRemove || s[j - 1] != close)) {

                    string next = s.substr(0, j) + s.substr(j + 1);

                    removeInvalid(next, i, j, open, close);
                }
            }

            return;
        }

        // No invalid ')' found
        reverse(s.begin(), s.end());

        if (open == '(') {
            // Now check for extra '('
            removeInvalid(s, 0, 0, ')', '(');
        } else {
            // Valid string found
            ans.push_back(s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        removeInvalid(s, 0, 0, '(', ')');

        return ans;
    }
};