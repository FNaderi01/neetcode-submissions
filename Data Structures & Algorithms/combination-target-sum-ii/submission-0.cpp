class Solution {
public:
    vector<vector<int>> res;
    void combinationRec(int idx, vector<int>& nums, int target,vector<int>& cur) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        if(idx == nums.size() || target < 0) {
            return;
        }

        int ptr = idx;
        while(ptr < nums.size() && nums[ptr] == nums[idx]) {
            ptr++;
        }
        int cnt = ptr - idx;
        for(int i = 0; i <= cnt; i++) {
            combinationRec(idx + cnt, nums, target - i * nums[idx], cur);
            cur.push_back(nums[idx]);
        }
    
        for(int i = 0; i <= cnt; i++) {
            cur.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        combinationRec(0, candidates, target, cur);
        return res;
    }
};
