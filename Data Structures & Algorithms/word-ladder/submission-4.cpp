class Solution {
    int n;
public:
    vector<vector<int>> buildGraph(string beginWord, map<string, int>& wordMap) {
        vector<vector<int>> ans(n);
        vector<bool> seen(n, false);

        for(auto[s, idx] : wordMap) {
            seen[idx] = true;
            for(int i = 0; i < s.size(); i++) {
                for(int j = 0; j < 26; j++) {
                    if('a' + j == s[i]) {
                        continue;
                    }
                    string cur = s;
                    cur[i] = 'a' + j;
                    if(wordMap.find(cur) != wordMap.end() && !seen[wordMap[cur]]) {
                        ans[idx].push_back(wordMap[cur]);
                        ans[wordMap[cur]].push_back(idx);
                    }
                }
            }
        }

        return ans;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        map<string, int> wordMap;
        for(int i = 0; i < n; i++) {
            wordMap[wordList[i]] = i;
        }

        if(wordMap.find(endWord) == wordMap.end()) {
            return 0;
        }

        if(wordMap.find(beginWord) == wordMap.end()) {
            wordMap[beginWord] = n;
            n++;
        }

        vector<vector<int>> g = buildGraph(beginWord, wordMap);
        vector<int> dist(n, 0);
        queue<int> q;

        dist[wordMap[beginWord]] = 1;
        q.push(wordMap[beginWord]);

        while(!q.empty()) {
            int top = q.front();
            q.pop();

            for(int u : g[top]) {
                if(dist[u] == 0) {
                    dist[u] = dist[top] + 1;
                    q.push(u);
                }
            }
        }

        return dist[wordMap[endWord]];
    }
};


// for(int i = 0; i < g.size(); i++) {
//     cout<<"Node: "<<i<<", Neighbors: ";
//     for(int x : g[i]) {
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }
