class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> arr(100005, 0);
        vector<int> solution;
        for(auto x:nums) {
            arr[x+50000]++;
        }
        for(int i = 0; i < 100005; i++) {
            while(arr[i]--) {
                solution.push_back(i - 50000);
            }
        }
        return solution;
    }
};