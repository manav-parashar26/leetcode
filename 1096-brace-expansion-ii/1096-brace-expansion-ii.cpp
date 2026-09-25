class Solution {
public:
    string s;
    int i = 0;

    set<string> unite(set<string> a, set<string> b) {
        a.insert(b.begin(), b.end());
        return a;
    }

    set<string> multiply(set<string> a, set<string> b) {
        set<string> res;

        for (auto x : a) {
            for (auto y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    // expression = term (',' term)*
    set<string> expression() {
        set<string> res = term();

        while (i < s.size() && s[i] == ',') {
            i++;

            set<string> next = term();
            res = unite(res, next);
        }

        return res;
    }

    // term = factor factor*
    set<string> term() {
        set<string> res;
        bool first = true;

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = factor();

            if (first) {
                res = cur;
                first = false;
            }
            else {
                res = multiply(res, cur);
            }
        }

        return res;
    }

    // factor = letter | { expression }
    set<string> factor() {
        if (s[i] == '{') {
            i++; // skip {

            set<string> res = expression();

            i++; // skip }

            return res;
        }

        set<string> res;
        res.insert(string(1, s[i]));

        i++;

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = this->expression();

        return vector<string>(ans.begin(), ans.end());
    }
};