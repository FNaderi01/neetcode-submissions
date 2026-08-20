class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>> zeros;
        unordered_set<int> col, row;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i : row) {
            for(int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }

        for(int i : col) {
            for(int j = 0; j < n; j++) {
                matrix[j][i] = 0;
            }
        }
    }
};
