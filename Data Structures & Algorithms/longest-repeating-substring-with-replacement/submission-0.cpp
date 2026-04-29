class Solution {
public:
    void change(map<char, int> &charToCount, set<pair<int, char> > &counts, char ch, int newVal) {
        int curVal = charToCount[ch];
        counts.erase({curVal, ch});
        charToCount[ch] = newVal;
        counts.insert({newVal, ch});
    }
    int characterReplacement(string s, int k) {
        map<char, int> charToCount;
        set<pair<int, char> >counts;
        int left = 0;
        int right = -1;
        int ans = 0;
        while(right + 1 < s.size()) {
            char ch = s[right+1];
            change(charToCount, counts, ch, charToCount[ch] + 1);
            if(check(right - left + 2, counts, k)) {
                right++;
                ans = max(ans, right-left+1);
                continue;
            }
            change(charToCount, counts, ch, charToCount[ch] - 1);
            change(charToCount, counts, s[left], charToCount[s[left]] - 1);
            left++;
        }
        return ans;

    }
    bool check(int l, set<pair<int, char> > &counts, int k) {
        auto biggest = *counts.rbegin();
        if(l - biggest.first <= k) return true;
        return false;
    }
};
