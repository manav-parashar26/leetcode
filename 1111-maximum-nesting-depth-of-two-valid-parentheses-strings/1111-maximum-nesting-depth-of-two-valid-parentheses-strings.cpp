class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cur = 0 ;
        vector<int> ans(seq.size());
        for(int i = 0 ; i < seq.size() ; i++){
            if(seq[i] == '('){
                cur++;
                ans[i] = cur%2;
            }
            else{
                ans[i] = cur%2;
                cur--;
            }
        }
        return ans;
    }
};