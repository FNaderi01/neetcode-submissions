class Solution {
    int n, m;
public:
    vector<pair<int, int>> getNeighbors(int x, int y, vector<vector<int>>& grid) {
        vector<pair<int, int>> ans;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                // cout<<x + i<<" "<<y + j<<endl;
                int diff = abs(i - j);
                if((diff == 0) || (diff == 2) || (x + i < 0) || (x + i >= n) ||
                   (y + j < 0) || (y + j >= m) || (grid[x + i][y + j] != 1)) {
                    // cout<<x + i<<" "<<y + j<<endl;
                    continue;
                }
                // cout<<x + i<<" "<<y + j<<endl;
                ans.push_back({x + i, y + j});
            }
        }

        return ans;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>>* cur = new queue<pair<int, int>>;
        queue<pair<int, int>>* next = new queue<pair<int, int>>;
        vector<vector<bool>> seen(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    cur->push({i, j});
                }
            }
        }

        cout<<cur->size()<<endl;
        int ans = 0;
        while(!cur->empty() || !next->empty()) {
            if(cur->empty()) {
                auto temp = cur;
                cur = next;
                next = temp;
                ans++;
            }

            int x = cur->front().first;
            int y = cur->front().second;
            cur->pop();

            for(auto[i, j] : getNeighbors(x, y, grid)) {
                if(!seen[i][j]) {
                    seen[i][j] = true;
                    next->push({i, j});
                }
            }

        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !seen[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
