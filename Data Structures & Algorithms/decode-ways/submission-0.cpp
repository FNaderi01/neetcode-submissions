class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n = s.size();
        int dp[n] = {0};
        dp[0] = 1;

        for(int i =1; i<n;i++){
            if(s[i] == '0'){
                if(!(s[i-1]=='1' || s[i-1] =='2')){
                    return 0;
                }
                if(i==1) dp[i] = 1;
                else dp[i] = dp[i-2];
                continue;
            }
            
            dp[i] = dp[i-1];
            if(s[i-1] == '1'|| (s[i] < '7' && s[i-1] == '2')){
                if(i==1){
                    dp[i]+=1;
                }
                else dp[i] += dp[i-2];
            }
        }
        return dp[n-1];
    }
};
