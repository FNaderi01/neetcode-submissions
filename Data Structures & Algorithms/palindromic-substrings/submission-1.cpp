class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        int ans=0;
        for(int i=0; i<n;i++){
            dp[i][i] = true;
            ans++;
        }
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                ans++;
            }
        }
        for(int sz = 3; sz <= n; sz++){
            for(int i=0; i+sz-1<n; i++){
                if(s[i] == s[i+sz-1] && dp[i+1][i+sz-2]){
                    dp[i][i+sz-1] = true;
                    ans++;
                }
                else dp[i][i+sz-1] = false;
            }
        }
        return ans;
    }
};
