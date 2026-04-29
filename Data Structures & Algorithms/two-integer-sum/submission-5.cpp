class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIdx;

        for(int i = 0; i < nums.size(); i++) {
            if (numToIdx.find(target - nums[i]) != numToIdx.end()) {
                vector<int> ans = {numToIdx[target - nums[i]], i};
                return ans;
            }
            numToIdx[nums[i]] = i;
        }
    }
};
