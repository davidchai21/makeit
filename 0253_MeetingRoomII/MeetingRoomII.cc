class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (vector<int>& interval : intervals) {
            if (!++m[interval[0]]) m.erase(interval[0]);
            if (!--m[interval[1]]) m.erase(interval[1]);
        }
        
        int cur = 0;
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            cur += it->second;
            res = max(res, cur);
        }
        return res;
    }
};