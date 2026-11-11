class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> items;
        for(auto x:points) {
            int distance = x[0] * x[0] + x[1] * x[1];
            items.push_back({distance, {x[0], x[1]}});
        }
        nth_element(items.begin(), items.begin() + k, items.end());
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(items[i].second);
        }
        return ans;
    }
};