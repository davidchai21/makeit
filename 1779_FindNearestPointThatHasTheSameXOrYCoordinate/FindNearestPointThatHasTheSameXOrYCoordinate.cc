class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        int index = -1;
        for (int i=0;i<points.size();++i) {
            if (points[i][0] != x && points[i][1] != y) continue;
            int dis = abs(x-points[i][0]) + abs(y-points[i][1]);
            if (res == -1) {
                res = dis;
                index = i;
            } else if (res > dis) {
                res = dis;
                index = i;
            }
        }
        return index;
    }
};