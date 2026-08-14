class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        unordered_map<int, int> freq; 

        int left = 0, length = 0; 

        for(int right = 0; right < s.size(); right++){

            freq[s[right]]++; 

            while(freq[s[right]] > 2){

                freq[s[left]]--; 
                left++; 
            }

            length = max(length, right - left + 1);
        }

        return length;  
    }
};