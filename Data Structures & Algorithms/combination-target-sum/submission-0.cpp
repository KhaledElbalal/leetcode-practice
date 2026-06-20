class Solution {
public:

    vector<vector<int>> sol;
    void solve(vector<int> &nums, int target, vector<int> curr) {
        if(target == 0) {
            sol.push_back(curr);
            return;
        }
        for(auto x:nums) {
            if(x <= target) {
                if(!curr.empty() && curr.back() < x) {
                    continue;
                }
                curr.push_back(x);
                solve(nums, target - x, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums, target, {});
        return sol;
    }
};
