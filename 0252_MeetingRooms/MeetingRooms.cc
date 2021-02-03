class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int endTime = intervals.front().back();
        for (int i=1;i<intervals.size();++i) {
            if (intervals[i].front() < endTime) return false;
            endTime = intervals[i].back();
        }
        return true;
    }
};