class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            isPal[i][i] = true;
            ans++;
            if(i + 1 < n && s[i] == s[i + 1]) {
                ans++;
                isPal[i][i + 1] = true;
            }
        }

        for(int l = 3; l <= n; l++) {
            for(int i = 0; i <= n - l; i++) {
                if(isPal[i + 1][i + l - 2] && s[i] == s[i + l - 1]) {
                    isPal[i][i + l - 1] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};
