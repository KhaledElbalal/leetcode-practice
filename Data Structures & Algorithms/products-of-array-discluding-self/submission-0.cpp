class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int totalProduct = 1, count_zero = count(nums.begin(), nums.end(), 0);
        for(auto x:nums) {
            if(x == 0) {
                continue;
            }
            totalProduct *= x;
        }
        for(auto x:nums) {
            if(x == 0 && count_zero < 2) {
                ans.push_back(totalProduct);
            } else if (x != 0 && count_zero == 1) {
                ans.push_back(0);
            } else if(count_zero > 1) {
                ans.push_back(0);
            } else
                ans.push_back(totalProduct/x);
        }
        return ans;
    }
};
