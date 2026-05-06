class Solution {
public:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);

        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return g;
    }

    void dfs(int v, int& cnt, vector<vector<int>>& g, vector<bool>&seen) {
        seen[v] = true;
        cnt++;

        for(int u : g[v]) {
            if(!seen[u]) {
                dfs(u, cnt, g, seen);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> g = buildGraph(n, edges);
        vector<bool> seen(n, false);
        int cnt = 0;
        dfs(0, cnt, g, seen);

        return (cnt == n);


    }
};
