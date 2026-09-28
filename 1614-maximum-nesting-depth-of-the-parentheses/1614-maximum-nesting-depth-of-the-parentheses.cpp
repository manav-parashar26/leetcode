class Solution {
public:
    int maxDepth(string s) {
        int p = 0;
        int ans = 0;
        for(auto x:s){
          if(x == '(')p++;
          else if(x == ')')p--;
          ans = max(ans,p);
        }
        return ans;
    }
};