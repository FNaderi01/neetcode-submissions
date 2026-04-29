class Solution {
public:
    vector<vector<int>> res;
    void combinationRec(int idx, int target, vector<int>& nums, vector<int>& cur) {
        if(target == 0) {
             res.push_back(cur);
             return;
        }
        if(idx == nums.size()) {
            return;
        }
        for(int i = 0; i * nums[idx] <= target; i++) {
            for(int j = 0; j < i; j++) {
                cur.push_back(nums[idx]);
            }

            combinationRec(idx + 1, target - i * nums[idx], nums, cur);
            for(int j = 0; j < i; j++) {
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        combinationRec(0, target, nums, cur);
        
        return res;
    }
};
