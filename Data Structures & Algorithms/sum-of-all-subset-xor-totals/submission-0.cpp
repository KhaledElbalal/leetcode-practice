class Solution {
public:
    int getXorSum(vector<int> &nums, int current = 0, int index = 0) {
        if(index == nums.size()) {
            return current;
        }
        return getXorSum(nums, current xor nums[index], index + 1) 
                + getXorSum(nums, current, index + 1); 
    }

    int subsetXORSum(vector<int>& nums) {
        return getXorSum(nums);
    }
};