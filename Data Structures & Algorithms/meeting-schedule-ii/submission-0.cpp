/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b) {
            if(a.start == b.start) {
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        vector<pair<int, int>> v;
        for(int i = 0; i < intervals.size(); i++) {
            v.push_back({intervals[i].start, 1});
            v.push_back({intervals[i].end, -1});
        }
        sort(v.begin(), v.end());
        int count = 0;
        int ans = 0;

        for(auto [t, q] : v) {
            count += q;
            ans = max(ans, count);
        }

        return ans;
    }
};
