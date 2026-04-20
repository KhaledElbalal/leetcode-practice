class Solution {
public:
    bool isValidArray(vector<int> arr) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > 1) {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> square(9,0), row(9,0), col(9,0);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(i % 3 == 0 && j % 3 == 0) {
                    vector<int> square(9,0);
                    for(int z = 0; z < 9; z++) {
                        if(board[i + z / 3][j + z % 3] != '.')
                            square[board[i + z / 3][j + z % 3] - '1']++;
                    }
                    if(!isValidArray(square))
                        return false;
                }
                if(board[i][j] != '.')
                    row[board[i][j] - '1']++;
                if(board[j][i] != '.')
                    col[board[j][i] - '1']++;
            }
            if(!(isValidArray(row) && isValidArray(col)))
                return false;
            row = col = vector<int> (9,0);
        }
        return true;
    }
};
