class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<long,vector<pair<int,int>>> sum_pairs;
        map<int,int> count;
        vector<int> temp_nums;
        for(auto x:nums) {
            count[x]++;
            if(count[x] < 5) {
                temp_nums.push_back(x);
            }
        }
        nums = temp_nums;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                sum_pairs[(long)nums[i] + (long)nums[j]].push_back({i,j});
            }
        }
        set<set<long>> temp;
        for(auto [u,v]:sum_pairs) {
            if(sum_pairs.count(target-u)) {
                for(auto x:v) {
                    for(auto y:sum_pairs[target-u]) {
                        temp.insert({x.first, x.second, y.first, y.second});
                    }
                } 
            }
        }
        vector<vector<int>> ans;
        for(auto x:temp) {
            if(x.size() == 4) {
                vector<int> temp_vec;
                for(auto y:x) {
                    temp_vec.push_back(nums[y]);
                }
                sort(temp_vec.begin(), temp_vec.end());
                if(find(ans.begin(), ans.end(), temp_vec) != ans.end()) 
                    continue;
                ans.push_back(temp_vec);
            }
        }
        return ans;
        
    }
};