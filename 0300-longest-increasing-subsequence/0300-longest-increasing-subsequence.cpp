class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> temp;

        for (int x : nums) {

            if (temp.empty() || x > temp.back()) {
                temp.push_back(x);
            } else {
                int idx =
                    lower_bound(temp.begin(), temp.end(), x) - temp.begin();

                temp[idx] = x;
            }
        }

        return temp.size();
    }
};