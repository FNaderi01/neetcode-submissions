class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end());
        stack<pair<int, int>> stk;
        stk.push(v[n - 1]);

        for(int i = n - 2; i >= 0; i--) {
            pair<int, int> fleet = stk.top();

            if((target - v[i].first) * fleet.second > (target - fleet.first) * v[i].second) {
                stk.push(v[i]);
            }
            
        }

        return stk.size();

        
    }
};
