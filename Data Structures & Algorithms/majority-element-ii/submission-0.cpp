class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 3;
        unordered_map<int,int> mp;
        for(auto x:nums) {
            mp[x]++;
        }
        vector<int> ans;
        for(auto [u,v]:mp) {
            if(v > threshold) {
                ans.push_back(u);
            }
        }
        return ans;
    }
};