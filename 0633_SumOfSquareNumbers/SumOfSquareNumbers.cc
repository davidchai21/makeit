class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 3) return true;
        int n = c/2;
        for (int i=0;i*i<=n;++i) {
            int d = c-i*i;
            int r = sqrt(d);
            if (r*r == d) return true;
        }
        return false;
    }
    
};