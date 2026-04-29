class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto t: strs) {
            s += t;
            s += '\0';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>v;
        string t = "";
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '\0') {
                v.push_back(t);
                t = "";
                continue;
            }
            t += s[i];
        }
        return v;
    }
};
