class Solution {
public:

    string vecToStr(vector<char> &x) {
        string ret = "";
        for(char ch: x)
            ret += ch;
        return ret;
    }
    void f(int n, int open, int close, vector<char> &cur, vector<string> &ans) {
        if(open == n && close == n) {
            ans.push_back(vecToStr(cur));
            return;
        }
        if(open == n) {
            cur.push_back(')');
            f(n, open, close+1, cur, ans);
            cur.pop_back();
            return;
        }
        if(open == close) {
            cur.push_back('(');
            f(n, open+1, close, cur, ans);
            cur.pop_back();
            return;
        }
        cur.push_back('(');
        f(n, open+1, close, cur, ans);
        cur.pop_back();
        cur.push_back(')');
        f(n, open, close+1, cur, ans);
        cur.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<char>v;
        vector<string>ans;
        f(n, 0, 0, v, ans);
        return ans;
    }
};
