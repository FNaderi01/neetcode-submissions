class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::priority_queue<std::pair<int, int>, 
                    std::vector<std::pair<int, int>>, 
                    std::greater<std::pair<int, int>>> minHeap;

        for(int i = 0; i < intervals.size(); i++) {
            minHeap.push({intervals[i][1], intervals[i][0]});
        }

        int cnt = 0;
        while(!minHeap.empty()) {
            auto cur = minHeap.top();
            minHeap.pop();
            
            while(!minHeap.empty() && minHeap.top().second < cur.first) {
                minHeap.pop();
                cnt++;
            }
        }

        return cnt;
    }
};
