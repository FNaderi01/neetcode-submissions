class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            int count[26] = {0};
            for (int j = 0; j < strs[i].size(); j++) {
                count[strs[i][j] - 'a']++;
            }


            string key = to_string(count[0]);
            for (int k = 1; k < 26; k++) {
                key += (',' + to_string(count[k]));
            }

            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};
