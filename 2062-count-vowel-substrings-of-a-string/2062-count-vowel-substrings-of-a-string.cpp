class Solution {
public:
    int countVowelSubstrings(string word) {
        int ans = 0;

        for(int i = 0; i < word.size(); i++) {
            set<char> st;

            for(int j = i; j < word.size(); j++) {
                if(word[j] == 'a' || word[j] == 'e' || 
                   word[j] == 'i' || word[j] == 'o' || 
                   word[j] == 'u') {
                    st.insert(word[j]);

                    if(st.size() == 5)
                        ans++;
                }
                else {
                    break;
                }
            }
        }

        return ans;
    }
};