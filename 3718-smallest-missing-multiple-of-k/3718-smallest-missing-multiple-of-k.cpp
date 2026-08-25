class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        vector<bool> present(n + 2, false);

        for (int x : nums) {
            if (x % k == 0) {
                int multiple = x / k;

                if (multiple <= n + 1) {
                    present[multiple] = true;
                }
            }
        }

        for (int i = 1; i <= n + 1; i++) {
            if (!present[i]) {
                return i * k;
            }
        }

        return -1;
    }
};