class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int k=5;k<=n;++k) {
            int sum = k*k;
            for (int i = 3;i*i<=sum/2;++i) {
                int j = sqrt(sum-i*i);
                if (j*j == sum-i*i) res += 2;
            }
        }
        return res;
    }
};