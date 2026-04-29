class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v;

        int i = 0;
        while (i < nums.size()) {
            int cnt = 0;
            while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
                cnt++;
                i++;
            }
            v.push_back({cnt, nums[i]});
            i++;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
