class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                int k = st.size();
                sum += k * k;
            }
        }

        return sum;
    }
};
// n = 4 1*1* 4 + 2*2*4 + 3*3*4
//1,2,3,4 