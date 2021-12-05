class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        sort(p.begin(), p.end());
        if (p[1] == p[0] || p[1] == p[2] || p[2] == p[3]) return false;
        auto f = [](const vector<int>& lhs, const vector<int>& rhs) {
            return (lhs[0]-rhs[0])*(lhs[0]-rhs[0])+(lhs[1]-rhs[1])*(lhs[1]-rhs[1]);
        };
        if (f(p[0], p[2])!=f(p[1],p[3]) || f(p[0], p[1])!=f(p[2],p[3]) || f(p[0], p[3])!=f(p[2],p[1]) || f(p[0], p[1])!=f(p[2],p[0])) return false;
        return true;
    }
};