class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            auto [word,step] = q.front();q.pop();
            if(word == endWord)return step;
            for(int i = 0 ; i < word.size() ; i++){
                char c = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,step + 1});
                    }
                }
                word[i] = c;
            }
        }
        return 0;
    }
};