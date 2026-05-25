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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0) {
            return true;
        }

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        if (a.start != b.start) {
            return a.start < b.start; // Primary sort condition
        }
        return a.end < b.end;         // Secondary sort condition
    });

        for(int i = 0; i < intervals.size() - 1; i++) {
            Interval a = intervals[i];
            Interval b = intervals[i + 1];

            if(b.start < a.end) {
                return false;
            }
        }

        return true;
    }
};
