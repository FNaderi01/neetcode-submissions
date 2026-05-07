class Solution {
public:
    bool compareWords(string s1, string s2) {
        bool sw = false;

        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) {
                if(sw) {
                    return false;
                }
                sw = true;
            }
        }

        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> g(n);
        vector<int> dist(n, -1);
        queue<int> q;

        int startIdx = -1, endIdx = -1;

        for(int i = 0; i < n; i++) {
            // if(beginWord == wordList[i]) {
            //     startIdx = i;
            // }
            if(endWord == wordList[i]) {
                endIdx = i;
            }

            for(int j = i + 1; j < n; j++) {
                if(compareWords(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        if(startIdx == -1) {
            vector<int> startAdj;
            for(int i = 0; i < n; i++) {
                if(compareWords(beginWord, wordList[i])) {
                    g[i].push_back(n);
                    startAdj.push_back(i);
                }
            }
            if(startAdj.size() == 0) {
                return 0;
            }

            g.push_back(startAdj);
            dist.push_back(1);
            startIdx = n;
            n = g.size();
        } else {
            dist[startIdx] = 1;
        }
        
        q.push(startIdx);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int u : g[cur]) {
                if(u == endIdx) {
                    return (dist[cur] + 1);
                }
                if(dist[u] == -1) {
                    dist[u] = dist[cur] + 1;
                    q.push(u);
                }
                
            }
        }

        return max(0, dist[endIdx]);
    }
};
