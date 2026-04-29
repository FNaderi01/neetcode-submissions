class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& mark, 
            int& cnt,int i, int j){
        
        if(grid[i][j] == 0) return;
        cnt++;
        mark[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();

        if(i-1>=0 && !mark[i-1][j]) dfs(grid, mark, cnt, i-1, j);
        if(i+1<n && !mark[i+1][j]) dfs(grid, mark, cnt, i+1, j);
        if(j-1>=0 && !mark[i][j-1]) dfs(grid, mark, cnt, i, j-1);
        if(j+1<m && !mark[i][j+1]) dfs(grid, mark, cnt, i, j+1);
        

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> mark;
        for(int i = 0 ; i < n ; i++) {
            mark.push_back(vector<bool>(m));
        }
        int ans=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(!mark[i][j]){
                    int t=0;
                    dfs(grid, mark, t, i, j );
                    ans = max(ans, t);
                }
            }
        }
        return ans;

    }
};
