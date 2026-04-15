class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < strs.size(); i++) {
            string cpy = strs[i];
            sort(cpy.begin(), cpy.end());
            mp[cpy].push_back(i);
        }
        vector<vector<string>> result(mp.size());
        int i = 0;
        for(auto [u,v]:mp) {
            for(auto x:v) {
                result[i].push_back(strs[x]);
            }
            i++;
        } 
        return result;
    }
};
