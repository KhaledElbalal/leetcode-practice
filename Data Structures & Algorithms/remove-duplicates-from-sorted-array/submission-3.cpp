class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1, r = 2, last_real = nums[0];
        while(r < nums.size() && l < nums.size()) {
            if(nums[l] <= last_real) {
                if(nums[r] > last_real) {
                    last_real = nums[r];
                    nums[l] = nums[r];
                    r++;
                    l++;
                } else {
                    r++;
                }
            } else {
                last_real = nums[l];
                l++;
            }
        }
        return l;
    }
};