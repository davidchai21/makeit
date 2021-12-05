class Solution {
public:
    int numWays(int n, int k) {
        if (k == 1) {
            return n > 2 ? 0 : 1;
        }
        
        int same = 0, diff = k, t;
        for (int i=1;i<n;++i) {
            t = same;
            same = diff;
            diff = (diff+t)*(k-1);
        }
        return same+diff;
    }
};