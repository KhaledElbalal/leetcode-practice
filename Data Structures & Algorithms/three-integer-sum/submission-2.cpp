class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<set<int>> unique_ans;
        map<int,vector<pair<int,int>>> mp;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                mp[nums[i] + nums[j]].push_back({i,j});
            }
        }
        for(int k = 0; k < nums.size(); k++) {
            auto it = mp.find(-nums[k]);
            if(it != mp.end()) {
                for(auto x:it->second) {
                    int i = x.first, j = x.second; 
                    if(k != i && k != j )   
                        unique_ans.insert({i,j,k});
                }
            }
        }
        set<vector<int>> ans;
        for(auto x:unique_ans) {
            vector<int> entry;
            for(auto y:x) {
                entry.push_back(nums[y]);
            }
            sort(entry.begin(), entry.end());
            ans.insert(entry);
            cout<<endl;
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};
