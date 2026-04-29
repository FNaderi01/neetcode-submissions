class Solution {
    bool check(unordered_map<char, int>& mt, unordered_map<char, int>& ms) {
        for(auto x : mt) {
            if(ms.find(x.first) == ms.end() || ms[x.first] < x.second) {
                return false;
            }
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> mt;
        unordered_map<char, int> ms;
        for(char ch : t) {
            mt[ch]++;
        }

        int l = 0;
        int ans = INT_MAX;
        int i = -1;

        for(int r = 0; r < s.size(); r++) {
            ms[s[r]]++;
            bool isValid = check(mt, ms);
            // cout<<l<<" "<<r<<" "<<isValid<<endl;
            while(isValid) {
                int len = (r - l + 1);
                if(len < ans) {
                    ans = len;
                    i = l;
                }

                char lch = s[l];
                ms[lch]--;
                l++;
                if(mt[lch] > ms[lch]) {
                    break;
                }
            }
        }
        if(i == -1) {
            return "";
        }
        return s.substr(i, ans);
    }
};
