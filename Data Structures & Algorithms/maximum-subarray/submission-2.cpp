class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingAtI = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            maxEndingAtI = max(maxEndingAtI + nums[i], nums[i]);
            ans = max(ans, maxEndingAtI);
        }

        return ans;
    }
};
