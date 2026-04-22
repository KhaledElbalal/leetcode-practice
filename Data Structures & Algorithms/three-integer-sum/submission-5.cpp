class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int k = 0; k < (int)nums.size(); k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k-1]) continue;

            int l = k + 1, r = (int)nums.size() - 1;
            while (l < r) {
                int sum = nums[k] + nums[l] + nums[r];
                if      (sum < 0) l++;
                else if (sum > 0) r--;
                else {
                    ans.push_back({nums[k], nums[l], nums[r]});
                    l = upper_bound(nums.begin() + l, nums.begin() + r, nums[l]) - nums.begin();
                    r = lower_bound(nums.begin() + l, nums.begin() + r, nums[r]) - nums.begin() - 1;
                }
            }
        }
        return ans;
    }
};