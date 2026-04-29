class Solution {
public:
    const int MAX_VAL = 2147483647;
    bool check(int i, int j, int n, int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }

    vector<pair<int, int>> neighbors(vector<vector<int>>& grid, int i, int j){
        vector<pair<int, int>> v;
        int n = grid.size();
        int m = grid[0].size();
        if(i-1>=0 && grid[i-1][j] != -1)
            v.push_back({i-1,j});
        if(i+1<n && grid[i+1][j] != -1)
            v.push_back({i+1,j});
        if(j-1>=0 && grid[i][j-1] != -1)
            v.push_back({i,j-1});
        if(j+1<m && grid[i][j+1] != -1)
            v.push_back({i,j+1});
        
        return v;
    }


    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> mark;
        for(int i=0; i<n;i++)
            mark.push_back(vector<bool> (m));    

        queue<pair<int, int>> q;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++)
                if(grid[i][j] == 0){
                    q.push({i,j});
                    mark[i][j] = true;
                }  
        }

        while(q.size()>0){
            auto u = q.front();
            q.pop();

            for(auto x: neighbors(grid, u.first, u.second)){
                if(!mark[x.first][x.second]){
                    mark[x.first][x.second] = true;
                    grid[x.first][x.second] = grid[u.first][u.second]+1;
                    q.push(x);
                }
    
            }
        }


    
        
    }
};
