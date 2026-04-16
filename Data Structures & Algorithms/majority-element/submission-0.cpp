class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums) {
            mp[x]++;
        }
        int max = 0, cnt = 0;
        for(auto [u,v]:mp) {
            if(v > cnt) {
                cnt = v;
                max = u;
            }
        }
        return max;
    }
};