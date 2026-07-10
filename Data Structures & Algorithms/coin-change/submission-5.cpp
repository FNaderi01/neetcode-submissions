class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            int c = coins[i];

            for(int j = 0; j <= amount; j++) {
                if(dp[j] != -1 && j + c <= amount) {
                    if(dp[j + c] == -1) {
                        dp[j + c] = dp[j] + 1;
                    } else {
                        dp[j + c] = min(dp[j + c], dp[j] + 1);
                    }
                }
            }
        }

        return dp[amount];
    }
};
