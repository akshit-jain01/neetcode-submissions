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
        if(intervals.empty()) return 0;
        priority_queue<int, vector<int>, greater<int>> q;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });
        int rooms = 1;
        q.push(intervals[0].end);
        for(int i = 1; i<n; i++)
        {
            int istart = intervals[i].start;
            int iend = intervals[i].end;
            while(!q.empty() && q.top() <= istart)
            {
                q.pop();
            }
            q.push(iend);
            rooms = max(rooms, (int)q.size());
        }

        return rooms;
    }
};
