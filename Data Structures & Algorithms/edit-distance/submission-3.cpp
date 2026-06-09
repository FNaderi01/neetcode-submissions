class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return word2.size();
        if(word2.size() == 0) return word1.size();
        vector<vector<int> > dp(word1.size(), vector<int>(word2.size(), 0));
        
        dp[0][0] = word1[0] != word2[0];
        for(int i = 1 ; i < word1.size() ; i++) {
            if(word1[i] != word2[0]) dp[i][0] = dp[i-1][0] + 1;
            else dp[i][0] = i;
        }
        for(int i = 1 ; i < word2.size() ; i++) {
            if(word1[0] != word2[i]) dp[0][i] = dp[0][i-1] + 1;
            else dp[0][i] = i;
        }
        for(int i = 1 ; i < word1.size() ; i++) {
            for(int j = 1 ; j < word2.size() ; j++) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }

        return dp[word1.size()-1][word2.size()-1];
        return 0;
    }
};