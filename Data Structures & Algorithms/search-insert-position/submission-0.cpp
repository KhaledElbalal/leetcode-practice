class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid = nums.size() / 2, low = 0, high = nums.size() - 1;
        int ans = mid;
        while(low <= high) {
            mid = (high + low) / 2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            } else if(nums[mid] < target) {
                ans = mid + 1;
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};