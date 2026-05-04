class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if((x - 1 >= 0) && (grid[x - 1][y] != -1) && !visited[x - 1][y]) {
                grid[x - 1][y] = min(grid[x - 1][y], grid[x][y] + 1);
                visited[x - 1][y] = true;
                q.push({x - 1, y});
            }

            if((x + 1 < n) && (grid[x + 1][y] != -1) && !visited[x + 1][y]) {
                grid[x + 1][y] = min(grid[x + 1][y], grid[x][y] + 1);
                visited[x + 1][y] = true;
                q.push({x + 1, y});
            }

            if((y - 1 >= 0) && (grid[x][y - 1] != -1) && !visited[x][y - 1]) {
                grid[x][y - 1] = min(grid[x][y - 1], grid[x][y] + 1);
                visited[x][y - 1] = true;
                q.push({x, y - 1});
            }

            if((y + 1 < m) && (grid[x][y + 1] != -1) && !visited[x][y + 1]) {
                grid[x][y + 1] = min(grid[x][y + 1], grid[x][y] + 1);
                visited[x][y + 1] = true;
                q.push({x, y + 1});
            }
        }
        
    }
};
