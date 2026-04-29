class Solution {
public:
    void updateMatch(int &match, unordered_map<char, int> &m1, unordered_map<char, int> &m2, char ch, int val) {
        if(m1.find(ch) == m1.end()) {
            m2[ch] = val;
            return;
        }

        if(m1[ch] == m2[ch]) {
            match--;
            m2[ch] = val;
            return;
        }
        m2[ch] = val;
        if(m1[ch] == m2[ch]) {
            match++;
        }

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

        int match = 0;
        for(auto x : m1){
            if(m2[x.first] == x.second) {
                match++;
            }
        }

        if(match == m1.size()) {
            return true;
        }

        for(int i = s1.size(); i < s2.size(); i++) {
            // cout<<i - 1<<", "<<match<<", "<<m1.size()<<endl;
            int start = i - s1.size();

            updateMatch(match, m1, m2, s2[start], m2[s2[start]] -1);
            updateMatch(match, m1, m2, s2[i], m2[s2[i]] + 1);

            if(match == m1.size()) {
                return true;
            }
            
        }

        return false;
    
    }
};
