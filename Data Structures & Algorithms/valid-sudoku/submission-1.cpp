class Solution {
public:
    bool checkRows(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            bool mark[10] = {0};
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                int cur = board[i][j] - '0';
                if(mark[cur]) {
                    return false;
                }
                mark[cur] = true;
            }
        }
        return true;
    }

    bool checkCols(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            bool mark[10] = {0};
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') {
                    continue;
                }
                int cur = board[j][i] - '0';
                if(mark[cur]) {
                    return false;
                }
                mark[cur] = true;
            }
        }
        return true;
    }

    bool checkBox(int x, int y, vector<vector<char>>& board) {
        bool mark[10] = {0};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[x+i][y+j] == '.') {
                    continue;
                }
                int cur = board[x+i][y+j] - '0';
                if(mark[cur]) {
                    return false;
                }
                mark[cur] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if(!checkRows(board) || !checkCols(board)) {
            return false;
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(!checkBox(i*3, j*3, board)) {
                    return false;
                }
            }
        }
        return true;
    }
};
