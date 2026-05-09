class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size());

        for(int i = 0; i < s.size(); i++) {
            for(string w : wordDict) {
                int l = w.size();
                if(l > (i + 1)) {
                    continue;
                }

                string sub = s.substr(i - l + 1, l);
                if(sub == w && ((i - l == -1) || dp[i - l])) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size() - 1];
    }
};
