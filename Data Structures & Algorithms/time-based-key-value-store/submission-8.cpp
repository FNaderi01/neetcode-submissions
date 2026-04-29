class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int left = 0, right = values.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};










// class TimeMap {
// private:
//     unordered_map <string, vector<pair<int,string>>> mp;
// public:
//     TimeMap() {

//     }
    
//     void set(string key, string value, int timestamp) {
//         mp[key].emplace_back(timestamp, value);
//     }
    
//     string get(string key, int timestamp) {
//         auto& a = mp[key];
//         int l =0, r = a.size()-1;
//         string ans = "";

//         while(l<=r){
//             int m = (l-r)/2 + l;
//             if(a[m].first<= timestamp){
//                 ans = a[m].second;
//                 l = m +1;
//             }
//             else{
//                 r = m-1;
//             }
//         }

//         return ans;
//     }
// };
