class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for(string x : strs) {
            int sz = x.size();
            result += (to_string(sz) + '#') + x;
        }
        // cout<<result;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        if(s.size() == 0) {
            return ret;
        }

        int i = 0;
        while (i < s.size()) {
            string str_sz;
            while (s[i] != '#') {
                str_sz += s[i];
                i++;
            }
            i++;
            // cout<<str_sz<<endl;
            int sz = stoi(str_sz);
            // cout<<sz<<endl;
            ret.push_back(s.substr(i, sz));
            i += sz;

        }
        return ret;
    }
};
