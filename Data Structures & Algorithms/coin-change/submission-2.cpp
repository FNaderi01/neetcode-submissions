class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // if(amount == 0) return 0;
        int dp[amount+1]={-1};
        for(int i=0 ; i<= amount;i++)
            dp[i] = -1;
        dp[0] = 0;
        for(int x:coins){
            if(x==amount) return 1;
            if(x<amount)
                dp[x] = 1;
        }

        for(int i=1; i<=amount; i++){
            
            int ans =1e6;
            for(int c:coins){
                // cout<<"Here"<<endl;
                if(i-c>0 && dp[i-c]>-1) {
                    // cout<<"Here"<<dp[i-c]<<endl;
                    ans = min(ans, dp[i-c]);
                }
            }
            if(ans != 1e6 && dp[i] ==-1) dp[i] = ans+1;
        }
        return dp[amount];
    }
};
