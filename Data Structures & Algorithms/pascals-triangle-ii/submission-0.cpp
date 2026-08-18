class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) {
            return {1};
        }
        vector<int> prevRow = getRow(rowIndex-1);
        vector<int> ans(rowIndex + 1, 1);
        for(int i = 1; i < rowIndex; i++) {
            ans[i] = prevRow[i-1] + prevRow[i];
        }
        return ans;
    }
};