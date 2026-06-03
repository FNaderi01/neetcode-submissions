class Solution {
    int target;
    vector<unordered_map<int, int>> dp;
public:
    int calc(int idx, int cur, vector<int>& nums) {
        if(cur == target && idx == nums.size()) {
            return 1;
        }

        if(idx == nums.size()) {
            return 0;
        }

        if(dp[idx].find(cur) != dp[idx].end()) {
            return dp[idx][cur];
        }

        dp[idx][cur] = calc(idx + 1, cur - nums[idx], nums) + calc(idx + 1, cur + nums[idx], nums);
        return dp[idx][cur];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        dp.resize(nums.size());

        return calc(0, 0, nums);
    }
};
