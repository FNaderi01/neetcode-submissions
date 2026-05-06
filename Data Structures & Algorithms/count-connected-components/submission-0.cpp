class Solution {
public:
    void dfs(int v, vector<vector<int>>& g, vector<bool>& seen) {
        seen[v] = true;

        for(int u : g[v]) {
            if(!seen[u]) {
                dfs(u, g, seen);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<bool> seen(n, false);

        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!seen[i]) {
                ans++;
                dfs(i, g, seen);
            }
        }

        return ans;
    }
};
