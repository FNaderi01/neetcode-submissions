class Solution {
public:
    int getMax(vector<int> &cnt) {
        int ans = 0;
        for(int i = 0; i < cnt.size(); i++) {
            ans = max(ans, cnt[i]);
        }

        return ans;
    }
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);

        int l = 0;
        int ans = 0;
        for(int r = 0; r < s.size(); r++) {
            int c = s[r] - 'A';
            cnt[c]++;

            int maxRep = getMax(cnt);
            int length = (r - l) + 1;
            if(length - maxRep <= k) {
                ans = max(ans, length);
            } else {
                cnt[s[l] - 'A']--;
                l++;
            }
        }

        return ans;
    }
};
