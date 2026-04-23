class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = (n * m) - 1;
        int mid = (high + low) / 2;
        while(low <= high) {
            int i = mid / m, j = mid % m;
            if(matrix[i][j] > target) {
                high = mid - 1;
            } else if(matrix[i][j] < target) {
                low = mid + 1;
            } else {
                return true;
            }
            mid = (high + low) / 2;
        }
        return matrix[mid / m][mid % m] == target;
    }
};
