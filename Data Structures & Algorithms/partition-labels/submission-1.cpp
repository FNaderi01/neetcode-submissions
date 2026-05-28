class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> v(26, {-1, -1});

        for(int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a';

            if(v[cur].first == -1) {
                v[cur] = {i, i};
            } else {
                v[cur].second = i;
            }
        }

        vector<pair<int, int>> sorted;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first != -1) {
                sorted.push_back(v[i]);
            }
        }
        
        sort(sorted.begin(), sorted.end());


        int curS = -1;
        int curE = -1;
        vector<int> ans;
        for(int i = 0; i < sorted.size(); i++) {
            pair<int, int> cur = sorted[i];

            if(curS == -1 && curE == -1) {
                curS = cur.first;
                curE = cur.second;
            } else {
                if(cur.first < curE) {
                    curE = max(curE, cur.second);
                } else {
                    ans.push_back(curE - curS + 1);
                    curS = cur.first;
                    curE = cur.second;
                }
            }
        }
        ans.push_back(curE - curS + 1);

        return ans;
    }
};
