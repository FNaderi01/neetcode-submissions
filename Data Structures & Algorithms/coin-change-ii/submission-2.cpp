class Solution {
public:

    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            for(int a = 1; a <= amount; a++) {
                if(coins[i] > a) {
                    continue;
                }

                dp[a] += dp[a - coins[i]];
            }
        }

        return dp[amount];
    }
};