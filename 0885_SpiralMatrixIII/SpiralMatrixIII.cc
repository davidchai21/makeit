class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int k=1;
        int x = r0, y = c0;
        int len = 1;
        vector<vector<int>> res;
        while (k<=R*C) {
            for (int i=0;i<len;++i) {
                if (isValid(x,y,R,C)) {
                    res.push_back({x,y});
                    ++k;
                }
                ++y;
            }
            for (int i=0;i<len;++i) {
                if (isValid(x,y,R,C)) {
                    res.push_back({x,y});
                    ++k;
                }
                ++x;
            }
            ++len;
            for (int i=0;i<len;++i) {
                if (isValid(x,y,R,C)) {
                    res.push_back({x,y});
                    ++k;
                }
                --y;
            }
            for (int i=0;i<len;++i) {
                if (isValid(x,y,R,C)) {
                    res.push_back({x,y});
                    ++k;
                }
                --x;
            }
            ++len;
        }
        return res;
    }
private:
    bool isValid(int x, int y, int R, int C) {
        return x>=0 && y>=0 && x<R && y<C;
    }
};