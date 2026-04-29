class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int num : st) {
            if (st.find(num - 1) != st.end()) {
                continue;
            }
            int cur = num;
            int streak = 1;
            while(st.find(cur + 1) != st.end()) {
                streak++;
                cur++;
            }
            ans = max(ans, streak);
        }
        return ans;
    }
};
