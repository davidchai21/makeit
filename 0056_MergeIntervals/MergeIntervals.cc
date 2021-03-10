class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        vector<int> t = intervals.front();
        for (int i=1;i<intervals.size();++i) {
            if (intervals[i].front() > t.back()) {
                res.push_back(t);
                t = intervals[i];
            } else {
                t[1] = max(t[1], intervals[i].back());
            }
        }
        res.push_back(t);
        return res;
    }
};