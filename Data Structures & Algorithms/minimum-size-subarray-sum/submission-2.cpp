class Solution {
public:
    bool validSubArrayOfLen(vector<int> &nums, int target, int size) {
        int total = 0;
        for(int i = 0; i < size; i++) {
            total += nums[i];
        }
        if(total >= target) return true;
        for(int j = 0; j < nums.size() - size; j++) {
            total -= nums[j];
            total += nums[size + j];
            if(total >= target) return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1, high = nums.size();
        int mid = (low + high) / 2;
        int ans = 0;
        while(low <= high) {
            mid = (low + high) / 2;
            if(validSubArrayOfLen(nums, target, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};