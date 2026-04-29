class Solution {
public:
    void updateSeen(int val, int x, int y, int n, vector<vector<int>>& seen) {
        for(int i = 0; i < n; i++) {
            seen[x][i] += val;
            seen[i][y] += val;
        }

        int cur_x = x;
        int cur_y = y;

        while(cur_x >=0 && cur_y >= 0) {
            seen[cur_x][cur_y] += val;
            cur_x--;
            cur_y--;
        }

        cur_x = x;
        cur_y = y;

        while(cur_x < n && cur_y < n) {
            seen[cur_x][cur_y] += val;
            cur_x++;
            cur_y++;
        }


        cur_x = x;
        cur_y = y;
        while((cur_x < n && cur_y < n) && (cur_x >=0 && cur_y >= 0)) {
            seen[cur_x][cur_y] += val;
            cur_x--;
            cur_y++;
        }

        cur_x = x;
        cur_y = y;
        while((cur_x < n && cur_y < n) && (cur_x >=0 && cur_y >= 0)) {
            seen[cur_x][cur_y] += val;
            cur_x++;
            cur_y--;
        }

    }
    void rec(int n, vector<string>& cur, vector<vector<string>>& ans, vector<vector<int>>& seen, int row) {
        if(cur.size() == n) {
            ans.push_back(cur);
            // cout<<"ppppppppppppppppppppppppppp"<<endl;
            return;
        }

        for(int i = 0; i < n; i++) {
            if(seen[row][i] == 0) {
                // cout<<row<<" "<<i<<endl;
                string s(n, '.');
                s[i] = 'Q';
                cur.push_back(s);
                updateSeen(1, row, i, n, seen);
                rec(n, cur, ans, seen, row + 1);
                updateSeen(-1, row, i, n, seen);
                cur.pop_back();
            }
        }

        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> seen(n, vector<int>(n, 0));
        vector<string> cur;
        rec(n, cur, ans, seen, 0);
        return ans;
    }
};
