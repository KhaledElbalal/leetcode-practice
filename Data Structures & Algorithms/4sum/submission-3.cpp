class Solution {
public:

    vector<vector<int>> kSum(vector<int> &nums, long target, int k, int l) {
        vector<vector<int>> sol;
        if(k == 2) {
            int r = nums.size() - 1;
            while(l < r) {
                long long s = (long long)nums[l] + nums[r];
                if (s < target) l++;
                else if (s > target) r--;
                else {
                    sol.push_back({nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++, r--;
                }
            }
            return sol;
        }
        for(int i = l; i < nums.size() - k + 1; i++) {
            if(i > l && nums[i] == nums[i-1]) continue;
            vector<vector<int>> partialSol = kSum(nums, target - nums[i], k - 1, i + 1);
            for(auto x:partialSol) {
                x.push_back(nums[i]);
                sol.push_back(x);
            }
        }
        return sol;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4, 0);
    }
};