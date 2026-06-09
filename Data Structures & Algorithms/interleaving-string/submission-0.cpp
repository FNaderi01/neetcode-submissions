class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();

        if(n + m != k) {
            return false;
        }

        if(n == 0 || m == 0) {
            return (s2 == s3 || s1 == s3);
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = false;
        dp[1][0] = (s1[0] == s3[0]);
        dp[0][1] = (s2[0] == s3[0]);

        for(int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] && s1[i - 1] == s3[i - 1]);
        }

        for(int i = 2; i <= m; i++) {
            dp[0][i] = (dp[0][i - 1] && s2[i - 1] == s3[i - 1]);
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                char cur = s3[i + j - 1];
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == cur) ||
                           (dp[i][j - 1] && s2[j - 1] == cur);
            }
        }

        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j <= m; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[n][m];
    }
};
