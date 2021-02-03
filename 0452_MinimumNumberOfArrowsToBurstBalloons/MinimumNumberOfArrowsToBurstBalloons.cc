class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int res = 1;
        int left = points.front().front();
        int right = points.front().back();
        for (int i=1;i<points.size();++i) {
            int l = max(left, points[i].front());
            int r = min(right, points[i].back());
            if (l > r) {
                ++res;
                left = points[i].front();
                right = points[i].back();
            } else {
                left = l;
                right = r;
            }
        }
        return res;
    }
};