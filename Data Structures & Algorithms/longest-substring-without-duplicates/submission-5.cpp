class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int l = 0;
        int ans = 0;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            if(m.find(c) != m.end()) {
                l = max(l, m[c] + 1);
            }

            m[c] = r;
            ans = max(ans, (r - l) + 1);

        }

        return ans;

    }
};
