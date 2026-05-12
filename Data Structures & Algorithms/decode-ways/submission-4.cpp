class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(s.size());
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                if(s[i - 1] != '1' && s[i - 1] != '2') {
                    return 0;
                }
                int temp = (i - 2 >= 0 ? dp[i - 2] : 1);
                dp[i] = temp;
            } else {
                if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {
                    int temp = (i - 2 >= 0 ? dp[i - 2] : 1);
                    dp[i] = dp[i - 1] + temp;
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }

        return dp[n - 1];
        
    }
};
