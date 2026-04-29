class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& mark) {
        if(grid[i][j] == '0')
            return;
        int n = grid.size();
        int m = grid[0].size();
        mark[i][j] = true;
        if(i + 1 < n && !mark[i+1][j]) dfs(grid, i+1, j, mark);
        if(i-1 >= 0 && !mark[i-1][j]) dfs(grid, i-1, j, mark);
        if(j + 1 < m && !mark[i][j+1]) dfs(grid, i, j+1, mark);
        if(j-1 >= 0 && !mark[i][j-1]) dfs(grid, i, j-1, mark);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> mark;
        for(int i = 0 ; i < n ; i++) {
            mark.push_back(vector<bool>(m));
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == '1' && !mark[i][j]) {
                    dfs(grid, i, j, mark);
                    ans++;
                }
            }
        return ans;
    }
};
