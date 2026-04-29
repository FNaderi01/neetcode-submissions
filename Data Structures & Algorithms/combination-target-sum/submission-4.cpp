class Solution {
    vector<vector<int>> combinationRec(int idx, int target, vector<int>& nums) {
        vector<vector<int>> ans;
        if(target == 0) {
             ans.push_back(vector<int>());
             return ans;
        }
        if(idx == nums.size()) {
            return ans;
        }
        for(int i = 0; i * nums[idx] <= target; i++) {
            vector<vector<int>> tmp = combinationRec(idx + 1, target - i * nums[idx], nums);
            for(vector<int> x : tmp) {
                for(int j = 1 ; j <= i ; j++) {
                    x.push_back(nums[idx]);
                }
                ans.push_back(x);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        vector<vector<int>> ans = combinationRec(0, target, nums);
        return ans;
    }
};
