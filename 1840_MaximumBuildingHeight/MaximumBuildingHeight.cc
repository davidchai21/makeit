class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty()) return n-1;
        restrictions.push_back({1,0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end());
        for (int i=1;i<restrictions.size();++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1]+restrictions[i][0]-restrictions[i-1][0]);
        }
        int res = restrictions.back().back();
        for (int i=restrictions.size()-1;i>0;--i) {
            restrictions[i-1][1] = min(restrictions[i-1][1], restrictions[i][1]+restrictions[i][0]-restrictions[i-1][0]);
            int h_max = max(restrictions[i].back(), restrictions[i-1].back());
            int h_min = min(restrictions[i].back(), restrictions[i-1].back());
            int h = h_max + (restrictions[i].front()-restrictions[i-1].front()-(h_max-h_min))/2;
            res = max(h, res);
        }
        return res;
    }
};