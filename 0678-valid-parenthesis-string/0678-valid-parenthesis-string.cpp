class Solution {
public:
    bool checkValidString(string s) {
        int minopen = 0 ,maxopen = 0;
        for(int i = 0 ;i<s.size();i++){
            if(s[i] == '('){
                minopen++;
                maxopen++;
            }else if(s[i] == ')'){
                minopen--;
                maxopen--;
            }
            else{
                minopen--;
                maxopen++;
            }
        if(minopen < 0)minopen =0;
        if(maxopen<0)return false;
        }
        return minopen==0;
    }
};