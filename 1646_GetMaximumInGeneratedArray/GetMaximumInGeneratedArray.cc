class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        vector<int> record(n+1, 0);
        record[1] = 1;
        int res = 1;
        for (int i=2;i<=n;++i) {
            if (i%2) {
                record[i] = record[i/2] + record[i/2+1];
            } else {
                record[i] = record[i/2];
            }
            res = max(res, record[i]);
        }
        return res;
    }
};