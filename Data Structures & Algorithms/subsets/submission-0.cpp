class Solution {
public:
    void subsetRec(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if(idx >= nums.size()) {
            vector<int> temp;
            ans.push_back(temp);
            return;
        }

        subsetRec(idx + 1, nums, ans);

        for(vector<int> x : ans) {
            vector<int> copied(x);
            copied.push_back(nums[idx]);
            ans.push_back(copied);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        subsetRec(0, nums, ans);
        return ans;
    }
};
