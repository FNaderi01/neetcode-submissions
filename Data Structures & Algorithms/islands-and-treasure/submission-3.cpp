class Solution {
public:
    vector<pair<int, int>> getNeighbors(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> ans;
        if(x - 1 >= 0 && grid[x - 1][y] != -1) {
            ans.push_back({x - 1, y});
        }
        if(x + 1 < n && grid[x + 1][y] != -1) {
            ans.push_back({x + 1, y});
        }
        if(y - 1 >= 0 && grid[x][y - 1] != -1) {
            ans.push_back({x, y - 1});
        }
        if(y + 1 < m && grid[x][y + 1] != -1) {
            ans.push_back({x, y + 1});
        }

        return ans;
    }
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

            for(auto[i, j] : getNeighbors(x, y, grid)) {
                if(!visited[i][j]) {
                    grid[i][j] = grid[x][y] + 1;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        
    }
};
