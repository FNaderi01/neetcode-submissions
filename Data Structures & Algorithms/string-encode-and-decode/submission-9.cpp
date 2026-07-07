class Solution {
public:
    string encodeWord(string s) {
        return to_string(s.size()) + "#" + s;
    }
    string encode(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs.size(); i++) {
            ans += encodeWord(strs[i]);
        }

        return ans;
    }

    string decodeWord(string s, int& idx) {
        string sz = "";
        while(s[idx] != '#') {
            sz += s[idx];
            idx++;
        }
        idx++;
        // cout<<sz<<endl;
        int size = stoi(sz);
        string ans = "";
        for(int i = 0; i < size; i++) {
            ans += s[i + idx];
        }
        idx += size;
        return ans;
    }
    vector<string> decode(string s) {
        int idx = 0;
        vector<string> ans;
        while(idx < s.size()) {
            string x = decodeWord(s, idx);
            ans.push_back(x);
        }

        return ans;
    }
};
