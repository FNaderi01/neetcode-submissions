class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        unordered_set<int> seen;

        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(seen.find(nums[i]) != seen.end()) {
                continue;
            }

            int cur = nums[i] + 1;
            int cnt = 1;
            while(s.find(cur) != s.end()) {
                seen.insert(cur);
                cur++;
                cnt++;
            }
            cur = nums[i] - 1;
            while(s.find(cur) != s.end()) {
                seen.insert(cur);
                cur--;
                cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
