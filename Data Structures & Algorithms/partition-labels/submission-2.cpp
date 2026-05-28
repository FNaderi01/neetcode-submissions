class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, -1);

        for(int i = 0; i < s.size(); i++) {
            int curChar = s[i] - 'a';

            v[curChar] = i;
        }

        vector<int> ans;
        int curS = 0;
        int curE = v[s[0] - 'a'];
        int curFar = curE;
        for(int i = 1; i < s.size(); i++) {
            if(i > curE) {
                ans.push_back(curE - curS + 1);
                curS = i;
                curE = v[s[i] - 'a'];
            } else {
                curE = max(curE, v[s[i] - 'a']);
            }
        }
        ans.push_back(curE - curS + 1);

        return ans;
        
    }
};
