/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> time;
        for (vector<Interval>& s : schedule) {
            for (Interval& i : s) {
                time.push_back(i);
            }
        }
        sort(time.begin(), time.end(), [](Interval& a, Interval& b){
            return a.start < b.start;
        });
        
        vector<Interval> res;
        int endtime = time.front().end;
        for (int i=1;i<time.size();++i) {
            if (time[i].start > endtime) {
                res.push_back(Interval(endtime, time[i].start));
                endtime = time[i].end;
            } else {
                endtime = max(endtime, time[i].end);
            }
        }
        return res;
    }
};