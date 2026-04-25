class Solution {
public:
    int findMin(vector<int> &nums) {
        // our answer is either: arr[0] or any arr[i] satisfies arr[i] < arr[i-1]
        // in typical binary search we have 3 elements
        // arr[l], arr[mid], arr[h]
        // if we compare arr[mid] to arr[l] and it is less that it 
        // it means the boundary element is still in the middle between them
        // otherwise the boundary element
        int low = 0, high = nums.size();
        int mid = (high + low) / 2;
        if(nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        while(low < high) {
            mid = (high + low) / 2;
            if(mid == 0 || nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            if(nums[mid] > nums[low]) {
                low = mid;
            } else  {
                high = mid;
            }
        }
        return nums[mid];
    }
};
