class Solution {
public:
    vector<vector<int>> arr;
    int getValue(int m, int n, int i, int j) {
        if(i == m || j == n) return 0;
        if(i == m - 1 && j == n - 1) return 1;
        if(arr[i][j] != 0) return arr[i][j];
        arr[i][j] = getValue(m, n, i + 1, j) + getValue(m, n, i, j + 1);
        return arr[i][j];
    }
    int uniquePaths(int m, int n) {
        arr = vector<vector<int>> (m, vector<int> (n,0));
        return getValue(m, n, 0, 0);
    }
};
