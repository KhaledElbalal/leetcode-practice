class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0, mid;
        int divider = 0;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] >= nums[0]) {
                divider = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 
        high = divider, low = 0;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        high = nums.size() - 1, low = divider + 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
