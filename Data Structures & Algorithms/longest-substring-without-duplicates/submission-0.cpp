class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int ans = 0;
        while(i < s.size()) {
            unordered_map<char, int> mark;
            mark[s[i]] = i;
            int curAns = 1;
            int j = i + 1;
            while(j < s.size() && mark.find(s[j]) == mark.end()) {
                mark[s[j]] = j;
                j++;
                curAns++;
                
            }

            ans = max(ans, curAns);
            if(j < s.size()) {
                i = mark[s[j]] + 1;
            } else {
                break;
            }
        }

        return ans;
    }
};
