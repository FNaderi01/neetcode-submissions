class Solution {
    int start, end;
public:
    void detect_dfs(int v, vector<vector<int>>& g, vector<bool>& seen, vector<int>& par) {
        seen[v] = true;

        for(int u : g[v]) {
            if(!seen[u]) {
                par[u] = v;
                detect_dfs(u, g, seen, par);
            } else if(u != par[v]) {
                start = v;
                end = u;
                return;
            }
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n + 1);
        vector<bool> seen(n + 1, false);
        vector<int> par(n + 1, -1);

        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        detect_dfs(1, g, seen, par);
        vector<int> ans;
        set<pair<int, int>> cycleEdges;
        cycleEdges.insert({start, end});
        cycleEdges.insert({end, start});

        while(end != start) {
            cycleEdges.insert({par[end], end});
            cycleEdges.insert({end, par[end]});
            end = par[end];
        }

        for(int i = n - 1; i >= 0; i--) {
            int a = edges[i][0];
            int b = edges[i][1];
            if(cycleEdges.find({a, b}) != cycleEdges.end())  {
                return {a, b};
            }
        }
        return ans;
    }
};
