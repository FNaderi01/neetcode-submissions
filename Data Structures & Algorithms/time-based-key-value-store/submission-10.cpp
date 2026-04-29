class TimeMap {
    
public:
    unordered_map <string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) {
            return "";
        }

        auto&  v = mp[key];
        int s = 0; 
        int e = v.size() - 1;
        int mid = 0;

        string ans = "";
        while(s <= e) {
            mid = (s + e) / 2;

            if(v[mid].first > timestamp) {
                e = mid - 1;
            } else if(v[mid].first <= timestamp) {
                ans = v[mid].second;
                s = mid + 1;
            }
        }

        return ans;
    }
};
