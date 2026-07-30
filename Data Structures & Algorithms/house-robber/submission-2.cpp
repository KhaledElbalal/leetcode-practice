class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        int ans = nums[0];
        dp[0] = nums[0];
        if(dp.size() > 1) {
            dp[1] = max(nums[0], nums[1]);
            ans = max(ans, dp[1]);
            for(int i = 2; i < nums.size(); i++) {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
