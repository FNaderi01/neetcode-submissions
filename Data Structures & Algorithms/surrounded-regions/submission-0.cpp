class Solution {
    int n, m;
    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
public:
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& seen) {
        seen[x][y] = true;

        if(isValid(x - 1, y) && board[x - 1][y] == 'O' && !seen[x - 1][y]) {
            dfs(x - 1, y, board, seen);
        }

        if(isValid(x + 1, y) && board[x + 1][y] == 'O' && !seen[x + 1][y]) {
            dfs(x + 1, y, board, seen);
        }

        if(isValid(x, y - 1) && board[x][y - 1] == 'O' && !seen[x][y - 1]) {
            dfs(x, y - 1, board, seen);
        }

        if(isValid(x, y + 1) && board[x][y + 1] == 'O' && !seen[x][y + 1]) {
            dfs(x, y + 1, board, seen);
        }

    }
    void solve(vector<vector<char>>& board) {
       n = board.size();
       m = board[0].size();
       vector<vector<bool>> seen(n, vector<bool>(m, false));

       for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O' && !seen[0][i]) {
                dfs(0, i, board, seen);
            }
            if(board[n - 1][i] == 'O' && !seen[n - 1][i]) {
                dfs(n - 1, i, board, seen);
            }
       }

       for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !seen[i][0]) {
                dfs(i, 0, board, seen);
            }
            if(board[i][m - 1] == 'O' && !seen[i][m - 1]) {
                dfs(i, m - 1, board, seen);
            }
       }

       for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!seen[i][j]) {
                    board[i][j] = 'X';
                }
            }
       }
    }
};
