#include <algorithm>
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compare(const Interval &i1, const Interval &i2)
{
    return i1.start < i2.start;
}
class Solution {
public:
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> v;
        sort(intervals.begin(), intervals.end(), compare);
        for(int i=0;i<intervals.size();i++)
        {
            Interval newInterval(intervals[i].start, intervals[i].end);
            while(i+1<intervals.size() && intervals[i+1].start <= newInterval.end)
            {
                if(intervals[i+1].end >= newInterval.end)
                    newInterval.end = intervals[i+1].end;
                i++;
            }
            v.push_back(newInterval);
        }
        return v;
    }
};
