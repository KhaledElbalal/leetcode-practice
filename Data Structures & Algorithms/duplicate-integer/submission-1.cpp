class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> res;
        for(auto x:nums) {
            if(res.contains(x)) {
                return true;
            }
            res[x] = 1;
        }
        return false;
    }
};