class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = max(nums[0], nums[1]);

        for(int i = 2 ; i < n ; i++) {
            dp[i][0] = max(nums[i] + dp[i-2][0], dp[i-1][0]);
            dp[i][1] = max(nums[i] + dp[i-2][1], dp[i-1][1]);
        }
        return max(dp[n-1][0], dp[n-2][1]);

    }
};
