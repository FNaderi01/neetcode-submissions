class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> next(numCourses);
        vector<int> numPre(numCourses);

        queue<int> q;

        for(vector<int> x : prerequisites) {
            int a = x[0];
            int b = x[1];
            next[b].push_back(a);
            numPre[a]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(numPre[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int u : next[cur]) {
                numPre[u]--;
                if(numPre[u] == 0) {
                    q.push(u);
                }
            }
        }

        for(int i = 0; i < numCourses; i++) {
            if(numPre[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
