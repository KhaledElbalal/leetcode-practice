class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        queue<int> ans;
        for(auto y: arr) {
            if(ans.size() == k && abs(ans.front() - x) > abs(y-x)) {
                ans.pop();
                ans.push(y);
            } else if(ans.size() != k) {
                ans.push(y);
            }
        }
        vector<int> ansArr;
        while(ans.size()) {
            ansArr.push_back(ans.front());
            ans.pop();
        }
        return ansArr;
    }
};