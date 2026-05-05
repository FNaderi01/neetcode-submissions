class Solution {
    int n, m;
public:
    int to1D(int i, int j) {
        return (i * m) + j;
    }
    vector<int> to2D(int x) {
        int i = x / m;
        int j = x % m;

        return {i, j};
    }
    vector<vector<int>> buildGraph(vector<vector<int>>& heights) {
        vector<vector<int>> g(n * m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) {
                    g[to1D(i, j)].push_back(to1D(i - 1, j));
                }

                if(i + 1 < n && heights[i + 1][j] >= heights[i][j]) {
                    g[to1D(i, j)].push_back(to1D(i + 1, j));
                }

                if(j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) {
                    g[to1D(i, j)].push_back( to1D(i, j - 1));
                }

                if(j + 1 < m && heights[i][j + 1] >= heights[i][j]) {
                    g[to1D(i, j)].push_back( to1D(i, j + 1));
                }
            }
        }

        return g;

    }

    void dfs(vector<vector<int>>& g, vector<bool>& seen, int v) {
        seen[v] = true;
        for(int u : g[v]) {
            if(!seen[u]) {
                dfs(g, seen, u);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> graph = buildGraph(heights);
        vector<bool> seenPac(n * m);
        vector<bool> seenAtl(n * m);

        for(int i = 0; i < m; i++) {
            dfs(graph, seenPac, to1D(0, i));
            dfs(graph, seenAtl, to1D(n - 1, i));
        }
        
        for(int i = 0; i < n; i++) {
            dfs(graph, seenPac, to1D(i, 0));
            dfs(graph, seenAtl, to1D(i, m - 1));
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n * m; i++) {
            if(seenPac[i] && seenAtl[i]) {
                ans.push_back(to2D(i));
            }
        }

        return ans;

    }
};