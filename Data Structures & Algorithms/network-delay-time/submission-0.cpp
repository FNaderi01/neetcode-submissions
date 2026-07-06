class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);

        for(int i = 0; i < times.size(); i++) {
            int s = times[i][0];
            int d = times[i][1];
            int t = times[i][2];

            g[s].push_back({d, t});
        }

        vector<int> dis(n + 1, INT_MAX);
        set<pair<int, int>> s;

        dis[k] = 0;
        s.insert({0, k});


        while(s.size() > 0) {
            auto cur = *s.begin();
            s.erase(s.begin());

            int distance = cur.first;
            int node = cur.second;

            for(int i = 0; i < g[node].size(); i++) {
                int weight = g[node][i].second;
                int neigh = g[node][i].first;

                if(dis[neigh] == INT_MAX || distance + weight < dis[neigh]) {
                    dis[neigh] = weight + distance;
                    s.insert({dis[neigh], neigh});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dis[i]);
        }

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};
