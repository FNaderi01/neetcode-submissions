class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int ans = 0;
        int curLen = 0;
        bool setLen = true;
        unordered_map<char, int> mp;
        while(i < s.size()) {
            
            int start;
            if(setLen) {
                start = i;
                curLen = 0;
                mp.clear();
            }
            // cout<<"i: "<<i<<", start:"<<start<<endl;
            int j = i + 1;
            if(mp.find(s[i]) == mp.end()) {
                curLen++;
            }
            mp[s[i]] = i;
            
            while(j < s.size() && mp.find(s[j]) == mp.end()) {
                mp[s[j]] = j;
                j++;
                curLen++;
            }
            // cout<<"j: "<<j<<endl;
            ans = max(curLen, ans);

            if(j == s.size()) {
                break;
            }

            if(mp[s[j]] == start) {
                start = start + 1;
                mp[s[j]] = j;
                setLen = false;
                i = j + 1;
            } else {
                i = j;
                setLen = true;
            }

        }

        return ans;
    }
};
