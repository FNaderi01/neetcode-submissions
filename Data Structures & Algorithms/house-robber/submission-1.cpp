class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            int rob = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int notRob = dp[i - 1];

            dp[i] = max(rob, notRob);
        }

        return dp[n - 1];
    }
};
