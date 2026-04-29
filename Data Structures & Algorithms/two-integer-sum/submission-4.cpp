class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> idxInfo;
        for(int i = 0; i < nums.size(); i++) {
            idxInfo.push_back({nums[i], i});
        }
      

        sort(idxInfo.begin(), idxInfo.end());
        int left = 0;
        int right = idxInfo.size() - 1;

        while (left < right) {
            int sum = idxInfo[left].first + idxInfo[right].first;
            if (sum == target) {
                int i = min(idxInfo[left].second, idxInfo[right].second);
                int j = max(idxInfo[left].second, idxInfo[right].second);
                vector<int> ans = {i, j};
                return ans;
            } 

            if (sum < target) {
                left++;
            } else {
                right--;
            }

        }
    }
};
