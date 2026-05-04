class Solution {
    int n;
    int m;
public:
    void dfs(int x, int y, int& cnt, vector<vector<int>>& grid, vector<vector<bool>>& seen) {
        seen[x][y] = true;
        cnt++;

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if((abs(i - j) > 1) || (i == j) || (x + i < 0) ||
                    (x + i >= n) || (y + j < 0) || (y + j >= m)) {
                        continue;
                }

                if(!seen[x + i][y + j] && grid[x + i][y + j] == 1) {
                    dfs(x + i, y + j, cnt, grid, seen);
                }
                

            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> seen(n, vector<bool>(m, false));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !seen[i][j]) {
                    int cnt = 0;
                    dfs(i, j, cnt, grid, seen);
                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};
