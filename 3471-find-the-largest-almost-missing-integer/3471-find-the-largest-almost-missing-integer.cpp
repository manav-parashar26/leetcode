class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> windowCount; // value -> number of windows containing it
        
        for (int s = 0; s + k <= n; s++) {
            unordered_set<int> seen;
            for (int i = s; i < s + k; i++) {
                seen.insert(nums[i]);
            }
            for (int v : seen) {
                windowCount[v]++;
            }
        }
        
        int ans = -1;
        for (auto& [val, cnt] : windowCount) {
            if (cnt == 1) {
                ans = max(ans, val);
            }
        }
        
        return ans;
    }
};