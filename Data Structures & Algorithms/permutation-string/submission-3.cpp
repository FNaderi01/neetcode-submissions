class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
        }

        vector<int> target(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            target[s1[i] - 'a']++;
        }
        vector<int> cur(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            cur[s2[i] - 'a']++;
        }

        bool check = true;
            for(int i = 0; i < 26; i++) {
                if(cur[i] != target[i]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                return true;
            }




        for(int i = s1.size(); i < s2.size(); i++) {
            int c = s2[i] - 'a';
            int s = s2[i - s1.size()] - 'a';
            cur[c]++;
            cur[s]--;

            bool check = true;
            for(int i = 0; i < 26; i++) {
                if(cur[i] != target[i]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                return true;
            }
        }

        return false;
    }
};
