class Solution {
    vector<vector<int>> combinationRec(int idx, int target, vector<int>& nums) {
        vector<vector<int>> ans;
        if(target == 0) {
            ans.push_back(vector<int>());
            return ans;
        }
        if(idx == nums.size() || target < 0) {
            return ans;
        }

        // Including me
        vector<vector<int>> v = combinationRec(idx, target - nums[idx], nums);
        for(auto& x : v) {
            x.push_back(nums[idx]);
        }
        //  Not including me
        vector<vector<int>> b = combinationRec(idx + 1, target, nums);

        if(b.size() == 0) {
            return v;
        }
        if(v.size() == 0) {
            return b;
        }

        for(auto x : v) {
            b.push_back(x);
        }

        return b;

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans = combinationRec(0, target, nums);
        return ans;
    }
};
