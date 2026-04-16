class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1, k = nums.size();
        while(i <= j) {
            if(nums[i] != val) {
                i++;
            } else if (nums[i] == val) {
                if(nums[j] != val) {
                    swap(nums[j], nums[i]);
                    i++;
                }
                k--;
                j--;
            }
        }
        return k;
    }
};