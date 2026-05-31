class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int leastFrequent = 0, leastFrequency = 0;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto x:nums) {
            mp[x]++;
        }
        for(auto [u,v]:mp) {
            pq.push({v,u});
        }
        while(k--) {
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        return ans;
    }
};
