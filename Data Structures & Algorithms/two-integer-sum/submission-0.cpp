class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> sum;
        for(int i = 0; i < nums.size(); i++) {
            if(sum.contains(target-nums[i])) {
                return {sum[target-nums[i]], i};
            } else {
                sum[nums[i]] = i;
            }
        }
    }
};
