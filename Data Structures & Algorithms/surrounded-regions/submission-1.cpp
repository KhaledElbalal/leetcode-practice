class Solution {
public:
    void color_in(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return;
        if(board[i][j] == 'X' || board[i][j] == 'o')
            return;
        else
            board[i][j] = 'o';
        color_in(board, i - 1, j);
        color_in(board, i, j - 1);
        color_in(board, i + 1, j);
        color_in(board, i, j + 1); 
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            if(i != 0 && i != board.size() - 1) {
                color_in(board, i, 0);
                color_in(board, i, board[0].size() - 1);
            } else {
                for(int j = 0; j < board[0].size(); j++) {
                    color_in(board, i, j);
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'o') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
