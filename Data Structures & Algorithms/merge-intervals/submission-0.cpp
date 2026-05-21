class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if(intervals.size() <= 1) {
        //     return intervals;
        // }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int curS = intervals[0][0];
        int curE = intervals[0][1];
        int p = 0;
        while(p < intervals.size()) {
            if(intervals[p][0] <= curE) {
                curE = max(curE, intervals[p][1]);
            } else {
                ans.push_back({curS, curE});
                curS = intervals[p][0];
                curE = intervals[p][1];
            }
            p++;
        }
        ans.push_back({curS, curE});
        return ans;


    }
};
