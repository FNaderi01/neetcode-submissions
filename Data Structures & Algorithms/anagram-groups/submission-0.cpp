class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        vector<vector<string>> o;
        for(int i=0; i< strs.size(); i++){
            string x = strs[i];
            sort(x.begin(), x.end()); 
            mp[x].push_back(strs[i]);
        }
        for(auto it = mp.begin(); it!=mp.end(); ++it){
            o.push_back(it->second);
        }
        return o;
    }
};
