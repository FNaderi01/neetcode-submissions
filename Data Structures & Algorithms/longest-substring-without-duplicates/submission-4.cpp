class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int l = 0;
        int ans = 0;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            if(m.find(c) == m.end()) {
                m[c] = r;
                ans = max(ans, r - l + 1);
                continue;
            }

            for(int j = l; j < m[c]; j++) {
                m.erase(s[j]);
            }
            l = m[c] + 1;
            m[c] = r;

        }

        return ans;

    }
};
