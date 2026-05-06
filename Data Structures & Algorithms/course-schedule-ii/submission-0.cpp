class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDeg(numCourses);
        vector<int> ans;
        queue<int> q;
        int visited = 0;

        for(auto x : prerequisites) {
            int a = x[0];
            int b = x[1];

            graph[b].push_back(a);
            inDeg[a]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(inDeg[i] == 0) {
                visited++;
                ans.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int u : graph[cur]) {
                inDeg[u]--;
                if(inDeg[u] == 0) {
                    visited++;
                    ans.push_back(u);
                    q.push(u);
                }
            }
        }

        if(visited != numCourses) {
            return {};
        }

        return ans;

    }
};
