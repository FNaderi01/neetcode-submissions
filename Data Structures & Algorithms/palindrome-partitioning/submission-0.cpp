class Solution {
public:
    bool isPal(string s, int l, int r) {
        while(l < r && s[l] == s[r]) {
            l++;
            r--;
        }
        return (l >= r);
    }
    void partitionRec(vector<string>& cur, vector<vector<string>>& ans, vector<vector<bool>>& isPalin, string s, int start) {
        if(start >= s.size() && cur.size() != 0) {
            ans.push_back(cur);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            if(isPalin[start][i]) {
                cur.push_back(s.substr(start, i - start + 1));
                partitionRec(cur, ans, isPalin, s, start + (i - start) + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<vector<bool>> isPalin(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                isPalin[i][j] = isPal(s, i, j);
            }
        }


        vector<string> cur;
        partitionRec(cur, ans, isPalin, s, 0);
        return ans;
    }
};