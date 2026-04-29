class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        pair<int, int> ans = {0,0};

        for(int i=0; i<n;i++){
            dp[i][i] = 1;
        }

        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                ans = {i, i+1};
            }
            else dp[i][i+1] = 0;
            
        }
        
        for(int sz = 3; sz<=n; sz++){
            for(int i = 0; i+sz-1 < n; i++){
                if(s[i] == s[i+sz-1] && dp[i+1][i+sz-2] ){
                    dp[i][i+sz-1] = 1;
                    ans = {i, i+sz-1};
                }
                else dp[i][i+sz-1] = 0;
            }
        }
        string ret = "";
        for(int i = ans.first; i<=ans.second;i++){
            ret+=s[i];
        }
        return ret;
    }
};
