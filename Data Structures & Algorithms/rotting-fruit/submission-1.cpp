class Solution {
public:
    const int MAX_VAL = 1e5;

    vector<pair<int, int>> neighbors(int i, int j, vector<vector<int>>& dst){
        int n = dst.size();
        int m = dst[0].size();
        vector<pair<int, int>> v;
        if(i-1>=0 && dst[i-1][j] != -1)
            v.push_back({i-1,j});
        if(j-1>=0 && dst[i][j-1] != -1)
            v.push_back({i, j-1});
        if(i+1 < n && dst[i+1][j]!= -1)
            v.push_back({i+1,j});
        if(j+1<m && dst[i][j+1] != -1)
            v.push_back({i, j+1});
        return v;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dst;
        vector<vector<bool>> mark;
        queue<pair<int, int>> q;
        for(int i=0; i<n;i++){
            dst.push_back(vector<int>(m));
            mark.push_back(vector<bool>(m));
            for(int j=0; j<m;j++){
                if(grid[i][j] == 0) dst[i][j] = -1;
                if(grid[i][j] == 1) dst[i][j] = MAX_VAL;
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    dst[i][j] = 0;
                    mark[i][j] = true;
                }
            }
            
        }
        // int ans =0; 
        
        while(q.size()>0){
            // cout<<q.size()<<endl;
            auto v = q.front(); q.pop();

            for(auto u: neighbors(v.first, v.second, dst)){
                // cout<<"HERE"<<endl;
                if(!mark[u.first][u.second]){
                    mark[u.first][u.second] = true;
                    dst[u.first][u.second] = dst[v.first][v.second]+1;
                    q.push(u);
                }
            }
        }
        int ans =0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(dst[i][j] == MAX_VAL) return -1;
                ans = max(ans, dst[i][j]);
            }
        }

        return ans;
        
    }
};
