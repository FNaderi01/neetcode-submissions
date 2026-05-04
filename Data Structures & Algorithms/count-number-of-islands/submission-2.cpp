class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& seen) {
        seen[x][y] = true;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if((abs(i - j) != 1) || (i == j) || (x + i < 0) || (x + i >= n) || 
                   (y + j < 0) || (y + j >= m)) {
                    continue;
                }
                if(!seen[x + i][y + j] && grid[x + i][y + j] == '1') {
                    dfs(x + i, y + j, grid, seen);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1' && !seen[i][j]) {
                    dfs(i, j, grid, seen);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
