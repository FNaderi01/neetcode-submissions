class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp = max(0, dp) + nums[i];
            ans = max(ans, dp);
        }
        return ans;
    }
};
