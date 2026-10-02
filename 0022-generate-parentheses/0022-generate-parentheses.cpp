class Solution {
public:
    void helper(string x , int open ,int close, int n ,vector<string>& ans){
        if(x.size() == 2*n){
            ans.push_back(x);
            return;
        }
        if(open < n){
            helper(x + '(' , open +1,close,n,ans);
        }
        if(close<open){
           helper(x + ')' , open,close + 1,n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("",0,0,n,ans);
        return ans;
    }
};