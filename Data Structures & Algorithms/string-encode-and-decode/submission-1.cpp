class Solution {
public:
    
    string encode(vector<string>& strs) {
        string s = "";
        for(auto t: strs) {
            s += to_string(t.size()) + '#' +  t;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>v;
        string t = "";
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] =='#'){
                int num = stoi(t);
                v.push_back(s.substr(i+1, num));
                i += num;
                t = "";
                continue;
            }
            t += s[i];
        }
        return v;
    }
};
