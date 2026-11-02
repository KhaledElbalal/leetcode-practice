class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        queue<int> ans;
        vector<int> ansArr;
        for(auto y: arr) {
            if(ans.size() == k && abs(ans.front() - x) > abs(y-x)) {
                ans.pop();
            }
            if(ans.size() != k) {
                ans.push(y);
            }
        }
        while(ans.size()) {
            ansArr.push_back(ans.front());
            ans.pop();
        }
        return ansArr;
    }
};