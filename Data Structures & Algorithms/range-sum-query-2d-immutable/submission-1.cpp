class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
            }
        }
        mat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; i++) {
            
            ans += mat[i][col2] - (col1 > 0 ? mat[i][col1-1] : 0);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */