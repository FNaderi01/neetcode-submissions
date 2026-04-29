class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 0);
        vector<int> zeroIdx;
        int all = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroIdx.push_back(i);
                continue;
            }
            all *= nums[i];
        }

        if (zeroIdx.size() > 1) {
            return output;
        } else if (zeroIdx.size() == 1) {
            output[zeroIdx[0]] = all;
            return output;
        }

        for (int i = 0; i < nums.size(); i++) {
            output[i] = all/nums[i];
        }
        return output;
    }
};
