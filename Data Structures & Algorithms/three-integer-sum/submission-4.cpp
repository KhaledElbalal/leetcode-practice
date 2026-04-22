class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());        
        vector<vector<int>> ans;
        for(int k = 0; k < nums.size(); k++) {
            if(k > 0 && nums[k] == nums[k-1])
                continue;
            cout << nums[k] << ' ';
            int target = -nums[k];
            int l = k + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] < target) l++;
                else if(nums[l] + nums[r] > target) r--;
                else if(nums[l] + nums[r] == target) {
                    ans.push_back({nums[k], nums[l], nums[r]});
                    int originalL = nums[l], originalR = nums[r];
                    while(nums[l] == originalL) l++;
                    while(nums[r] == originalR) r--;
                }
            }
        }
        return ans;
    }
};
