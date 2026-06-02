class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) {
            if(text1[0] == text2[i]) {
                dp[0][i] = 1;
            } else if(i > 0) {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for(int i = 0; i < n; i++) {
            if(text2[0] == text1[i]) {
                dp[i][0] = 1;
            } else if( i > 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                int cur = dp[i - 1][j - 1];
                if(text1[i] == text2[j]) {
                    cur += 1;
                }

                dp[i][j] = max(cur, max(dp[i - 1][j], dp[i][j - 1]));
            }
        }

        return dp[n - 1][m - 1];
    }
};
