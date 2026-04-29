class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) {
            return ans;
        }
        vector<vector<char>> v(10);
        v[2] = {'a', 'b', 'c'};
        v[3] = {'d', 'e', 'f'};
        v[4] = {'g', 'h', 'i'};
        v[5] = {'j', 'k', 'l'};
        v[6] = {'m', 'n', 'o'};
        v[7] = {'p', 'q', 'r', 's'};
        v[8] = {'t', 'u', 'v'};
        v[9] = {'w', 'x', 'y', 'z'};

        // vector<string> ans;
        string s = "";

        rec(v, digits, s, ans, 0);
        return ans;

    }

    void rec(vector<vector<char>>& v, string& digits, string &cur, vector<string>& ans, int pos) {
        if(cur.size() == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for(char c : v[digits[pos] - '0']) {
            cur.push_back(c);
            rec(v, digits, cur, ans, pos + 1);
            cur.pop_back();
        }
    }
};
