class Solution {
public:
    bool check(string s,int start,int end){
        while(start <= end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    void help(int idx,string s,vector<vector<string>>& ans,vector<string>& path){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = idx ; i<s.size();i++){
            if(check(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                help(i+1,s,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        help(0,s,ans,path);
        return ans;
    }
};