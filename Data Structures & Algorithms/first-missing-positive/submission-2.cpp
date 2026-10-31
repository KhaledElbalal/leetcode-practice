class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int checkpoint = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 1 || nums[i] > n) {
                nums[i] = 0;
                continue;
            } else if(nums[i] - 1 != i) {
                if(nums[i] == nums[nums[i] - 1]) {
                    nums[i] = 0;
                } else {
                    swap(nums[i], nums[nums[i] - 1]);
                    i--;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};