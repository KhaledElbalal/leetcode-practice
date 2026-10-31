class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        int checkpoint = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ans) {
                ans++;
                i = checkpoint - 1;
            } else if(nums[i] > ans && nums[checkpoint] <= ans) {
                checkpoint = i;
            }
        }
        return ans;
    }
};