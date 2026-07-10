class Solution {
public:
    bool isValid(char first, char second) {
        int a = first - '0';
        int b = second - '0';

        if(a == 0 || a > 2 || (a == 2 && b > 6)) {
            return false;
        }

        return true;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);
        if(s[0] == '0') {
            return 0;
        }
        if(n == 1) {
            return 1;
        }

        if(s[0] > '2' && s[1] == '0') {
            return 0;
        }
        dp[0] = 1;
        if((s[0] <= '2' && s[1] == '0') || s[0] > '2' || (s[0] == '2' && s[1] > '6')) {
            dp[1] = 1;
        } else {
            dp[1] = 2;
        }

        for(int i = 2; i < n; i++) {
            bool check = isValid(s[i - 1], s[i]);
            if(!check && s[i] == '0') {
                return 0;
            }

            if(check && s[i] == '0') {
                dp[i] = dp[i - 2];
            } else if (check){
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[n - 1];

    }
};
