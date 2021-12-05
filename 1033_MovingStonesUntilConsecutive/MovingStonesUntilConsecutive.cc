class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        array<int, 3> s = {a, b, c};
        sort(s.begin(), s.end());
        vector<int> res(2,2);
        res[1] = s.back()-s.front()-2;
        if (s[1]-s[0] == 1 && s[2]-s[1] == 1) res[0] = 0;
        else if (s[1]-s[0] < 3 || s[2]-s[1]<3) res[0] = 1;
        return res;
    }
};