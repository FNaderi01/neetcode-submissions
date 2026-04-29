class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> ans;

    void rec(int n, vector<string>& cur, int row) {
        if(row == n) {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < n; i++) {
            if (col.count(i) || posDiag.count(row + i) ||
                negDiag.count(row - i)) {
                continue;
            }
            
            cur[row][i] = 'Q';
            col.insert(i);
            posDiag.insert(row + i);
            negDiag.insert(row - i);

            rec(n, cur, row + 1);
            

            cur[row][i] = '.';
            col.erase(i);
            posDiag.erase(row + i);
            negDiag.erase(row - i);
            
        }

        
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> cur(n, s);
        rec(n, cur, 0);
        return ans;
    }
};
