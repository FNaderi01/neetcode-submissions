class Solution {
    vector<vector<int>> combinationRec(int idx, int target, vector<int>& nums) {
        vector<vector<int>> ans;
        if(idx >= nums.size()) {
            return ans;
        }
        if(nums[idx] == target) {
            vector<int> v;
            v.push_back(nums[idx]);
            ans.push_back(v);
            return ans;
        }
        if(target == 0) {
            vector<int> v;
            ans.push_back(v);
            return ans;
        }

        for(int i = 0; i * nums[idx] <= target; i++) {
            vector<int> rep(i, nums[idx]);
            if(i * nums[idx] == target) {
                ans.push_back(rep);
                return ans;
            }

            vector<vector<int>> tmp = combinationRec(idx + 1, target - i * nums[idx], nums);
            for(vector<int> x : tmp) {
                for(int y : rep) {
                    x.push_back(y);
                }
                ans.push_back(x);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = combinationRec(0, target, nums);
        return ans;
    }
};
