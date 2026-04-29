class Solution {
public:
    void subsetRec(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
             ans.push_back(cur);
            return;
        }

        // How many have value nums[idx]?
        int cnt = idx;
        while(nums[cnt] == nums[idx]) {
            cnt++;
        }
        cnt = cnt - idx;

        for(int i = 0; i <= cnt; i++) {
            subsetRec(idx + cnt, nums, cur, ans);
            cur.push_back(nums[idx]);
        }

        for(int i = 0; i <= cnt; i++) {
            
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        subsetRec(0, nums, cur, ans);
        return ans;
    }
};
