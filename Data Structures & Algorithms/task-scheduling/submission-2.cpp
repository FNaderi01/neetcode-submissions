class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        priority_queue<pair<int, char>> pq; // {frequency, task}
        queue<pair<int, char>> q; // {lastCalled, task}
        int curCycle = 0;

        for(char ch : tasks) {
            v[ch - 'A']++;
        }

        for(int i = 0; i < 26; i++) {
            if(v[i] != 0) {
                pq.push({v[i], i + 'A'});
            }   
        }
        int jump = 1;
        while(!pq.empty() || !q.empty()) {
            curCycle += jump;
            if(!q.empty() && (curCycle - q.front().first - 1 >= n)) {
                auto c = q.front();
                pq.push({v[c.second - 'A'], c.second});
                q.pop();
            }

            if(!pq.empty()) {
                pair<int, char> next = pq.top();
                pq.pop();

                if(next.first > 1) {
                    q.push({curCycle, next.second});
                    v[next.second - 'A']--;
                }
                jump = 1;
            } else {
                pair<int, char> candid = q.front();
                q.pop();
                pq.push({v[candid.second - 'A'], candid.second});
                jump = max(0, (candid.first + n + 1) - curCycle);
            }
        }

        return curCycle;
        
    }
};
