class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v;
        int i = 0;
        while(i < n) {
            int cur = nums[i];
            int cnt = 1;
            while(i + 1 < n && nums[i + 1] == cur) {
                cnt++;
                i++;
            }
            i++;

            v.push_back({cnt, cur});

        }

        sort(v.begin(), v.end());
        vector<int> ans;
        n = v.size();
        for(int j = 0; j < k; j++) {
            // cout<<v[n - 1 - j].second<<endl;
            ans.push_back(v[n - 1 - j].second);
        }

        return ans;
    }
};
