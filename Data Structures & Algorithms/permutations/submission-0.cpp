class Solution {
public:
    void permuteRec(vector<bool>& seen, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(seen[i] == false) {
                seen[i] = true;
                cur.push_back(nums[i]);
                permuteRec(seen, nums, cur, ans);
                cur.pop_back();
                seen[i] = false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> seen(nums.size(), false);
        vector<int> cur;
        vector<vector<int>> ans;

        permuteRec(seen, nums, cur, ans);
        return ans;
    }
};
