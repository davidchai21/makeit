class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        int res = 0;
        for (vector<int>& r : rectangles) {
            int curLen = min(r[0], r[1]);
            if (maxLen < curLen) {
                res = 1;
                maxLen = curLen;
            } else if (maxLen == curLen) ++res;
        }
        return res;
    }
};