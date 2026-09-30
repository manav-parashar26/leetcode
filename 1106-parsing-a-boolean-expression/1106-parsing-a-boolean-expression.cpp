class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> st;

        for (char c : expression) {

            if (c == ',')
                continue;

            if (c != ')') {
                st.push(c);
            } else {
                bool t = false;
                bool f = false;

                while (st.top() != '(') {
                    char x = st.top();
                    st.pop();

                    if (x == 't')
                        t = true;
                    else
                        f = true;
                }

                st.pop(); // remove '('

                char op = st.top();
                st.pop();

                if (op == '!') {
                    st.push(f ? 't' : 'f');
                } else if (op == '&') {
                    st.push(f ? 'f' : 't');
                } else {
                    st.push(t ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};