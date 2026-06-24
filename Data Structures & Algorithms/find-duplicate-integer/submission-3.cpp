class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int targetPosition = nums[i] - 1;
            if(i == targetPosition) {
                continue;
            }
            else if(nums[i] == nums[targetPosition]) {
                return nums[i];
            } else {
                swap(nums[i], nums[targetPosition]);
                i = targetPosition;
            }
        }
        return nums[0];
    }
};
