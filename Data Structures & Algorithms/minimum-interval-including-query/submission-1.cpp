class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> qs(queries.begin(), queries.end());
        unordered_map<int, int> m;

        sort(intervals.begin(), intervals.end());
        sort(qs.begin(), qs.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int i = 0;
        for(int q : qs) {
            while(i < intervals.size() && intervals[i][0] <= q) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({len, intervals[i][1]});
                i++;
            }

            while(!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }

            m[q] = minHeap.empty() ? -1 : minHeap.top().first;
        }

        vector<int> ans(queries.size());
        for(int j = 0; j < queries.size(); j++) {
            ans[j] = m[queries[j]];
        }
        
        return ans;
    }
};
