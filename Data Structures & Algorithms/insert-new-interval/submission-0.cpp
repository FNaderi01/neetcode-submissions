class Solution {
public:
    bool haveConflict(vector<int>& a, vector<int>& b, vector<int>& cnf) {
        if(b[0] <= a[1] && b[1] >= a[0]) {
            cnf[0] = min(b[0], a[0]);
            cnf[1] = max(a[1], b[1]);
            return true;
        }

        if(a[0] <= b[1] && a[1] >= b[0]) {
            cnf[0] = min(b[0], a[0]);
            cnf[1] = max(a[1], b[1]);
            return true;
        }
        return false;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n == 0) {
            ans.push_back(newInterval);
            return ans;
        }

        int p = 0;
        vector<int> cnf = {0, 0};
        bool done = false;
        while(p < n) {
            if(!haveConflict(intervals[p], newInterval, cnf)) {
                if(intervals[p][1] < newInterval[0]) {
                    ans.push_back(intervals[p]);
                } else {
                    ans.push_back(newInterval);
                    done = true;
                    break;
                }
            } else {
                newInterval = cnf;
            }
            p++;
        }

        if(done) {
            while(p < n) {
                ans.push_back(intervals[p]);
                p++;
            }
            return ans;
        }
        if(p == n) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};
