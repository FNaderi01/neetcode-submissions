class Solution {
public:
    bool check(int pa, int pb, int sa, int sb, int target) {
        return (target - pa) * sb >= (target - pb) * sa;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> helper;

        for(int i = 0; i < position.size(); i++) {
            helper.push_back({position[i], i});
        }
        sort(helper.begin(), helper.end());
        reverse(helper.begin(), helper.end());
        int i = 0;
        int ans = 0;
        while(i < helper.size()) {
            int j = i + 1;
            while(j < helper.size() && check(helper[i].first, helper[j].first, speed[helper[i].second], 
                                             speed[helper[j].second], target)) {
                j++;
            }
            i = j;
            ans++;
        }
        return ans;
    }
};