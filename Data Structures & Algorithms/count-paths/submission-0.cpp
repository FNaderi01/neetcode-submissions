class Solution {
    vector<vector<int>> dp;
public:
    int calc(int x, int y) {
        if(x < 0 || y < 0) {
            return 0;
        }

        if(dp[x][y] != 0) {
            return dp[x][y];
        }

        if(x == 0 && y == 0) {
            dp[0][0] = 1;
            return 1;
        }
        
        dp[x][y] = calc(x - 1, y) + calc(x, y - 1);
        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, 0));
        return calc(m - 1, n - 1);
    }
};
