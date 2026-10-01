class Solution {
public:
    string encode(string str) {
        int arr[26] = {0};
        for(char ch : str) {
            arr[ch - 'a']++;
        }

        string ans = "";
        for(int i = 0; i < 26; i++) {
            ans += (char)('a' + i);
            ans += to_string(arr[i]);
        }

        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& s : strs) {
            string encoded = encode(s);
            mp[encoded].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};
