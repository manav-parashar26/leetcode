class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totsum = 0;
        for(int i = 0 ; i < nums.size() ; i++)totsum += nums[i];
        if(totsum % 2)return false;
        int sum = totsum / 2;
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        for(auto x :nums){
            for(int target = sum ; target >= x ;target--){
                dp[target] = dp[target] || dp[target-x];
            }
        }
        return dp[sum];
    }
};