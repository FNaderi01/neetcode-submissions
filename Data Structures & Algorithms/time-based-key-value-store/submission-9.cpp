class TimeMap {
private:
    unordered_map <string, vector<pair<int,string>>> mp;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& a = mp[key];
        int l =0, r = a.size()-1;
        string ans = "";

        while(l<=r){
            int m = (r-l)/2 + l;
            if(a[m].first<= timestamp){
                ans = a[m].second;
                l = m +1;
            }
            else{
                r = m-1;
            }
        }

        return ans;
    }
};
