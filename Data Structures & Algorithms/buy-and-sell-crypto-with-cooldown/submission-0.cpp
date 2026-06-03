class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> dp(n, 0);

        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            for(int j = i - 1; j >= 0; j--) {
                int temp = (prices[i] - prices[j]) + (j - 2 >= 0 ? dp[j - 2] : 0);
                dp[i] = max(dp[i], temp);
            }
        }

        return dp[n - 1];
    }
};
