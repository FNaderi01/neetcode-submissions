class Solution {
public:
    bool isper(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for(auto p : m1) {
            if(m2[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) {
            return false;
        }

        unordered_map<char, int> m1, m2;
        for(char ch : s1) {
            m1[ch]++;
        }

        for(int i = 0; i < s1.size(); i++) {
            m2[s2[i]]++;
        }

        if(isper(m1, m2)) {
            return true;
        }

        for(int i = s1.size(); i < s2.size(); i++) {
            m2[s2[i - s1.size()]]--;
            m2[s2[i]]++;
            if(isper(m1, m2)) {
                return true;
            }
        }

        return false;
    
    }
};
