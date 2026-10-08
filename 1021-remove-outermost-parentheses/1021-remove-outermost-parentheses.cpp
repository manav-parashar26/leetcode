class Solution {
public:
    string removeOuterParentheses(string s) {
      int count = 0;
      string ans = "";
      for(auto c:s){
        if( c == ')') count--;
        if( count != 0) ans.push_back( c);
        if( c == '(') count++;
      }  
      return ans;
    }
};