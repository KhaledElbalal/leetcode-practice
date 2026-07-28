class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        k = k % nums.size();
        for(int i = nums.size() - k; i < nums.size(); i++) {
            ans[i - (nums.size() - k)] = nums[i];
        }
        for(int i = 0; i < nums.size() - k; i++) {
            ans[i + k] = nums[i];
        }
        nums = ans;
    }
};