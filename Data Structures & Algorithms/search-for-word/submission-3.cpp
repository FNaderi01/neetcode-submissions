class Solution {
public:
    bool existRec(string &cur, string word, int x, int y, vector<vector<char>>& board, vector<vector<bool>>& seen) {
        if(cur == word) {
            return true;
        }

        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || 
          seen[x][y] || cur.size() > word.size() || word[cur.size()] != board[x][y]) {
            return false;
        }
        
        cur.push_back(board[x][y]);
        seen[x][y] = true;

        bool ret = existRec(cur, word, x - 1, y, board, seen) ||
                   existRec(cur, word, x + 1, y, board, seen) ||
                   existRec(cur, word, x, y - 1, board, seen) ||
                   existRec(cur, word, x, y + 1, board, seen);

        cur.pop_back();
        seen[x][y] = false;

        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                string cur = "";
                if(existRec(cur, word, i, j, board, seen)) {
                    return true;
                }
            }
        }

        return false;
    }
};
