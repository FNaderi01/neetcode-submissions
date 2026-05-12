class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum % 2 == 1) {
            return false;
        }

        int k = sum / 2;
        vector<bool> dp(k + 1, false);
        for(int c : nums) {
            for(int i = k; i >= 1; i--) {
                if(c > i) {
                    break;
                }
                if(dp[i - c] || i == c) {
                    dp[i] = true;
                }
            }
        }

        return dp[k];

    }
};
