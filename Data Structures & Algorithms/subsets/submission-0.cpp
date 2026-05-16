class Solution {
public:
    vector<vector<int>> ans;
    void getArray(vector<int> &main, vector<int> current, int pos) {
        if(pos >= main.size()) {
            return;
        }
        getArray(main, current, pos + 1);
        current.push_back(main[pos]);
        ans.push_back(current);
        getArray(main, current, pos + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        getArray(nums, {}, 0);
        return ans;
    }
};
