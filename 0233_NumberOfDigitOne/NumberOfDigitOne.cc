class Solution {
public:
    int countDigitOne(int n) {
        long res = 0;
        for (int i=1;i<=n;i*=10) {
            long long d = i*10LL;
            int r = n%d;
            int mid = r/i;
            int left = n/d;
            int right = n%i;
            if (!mid) res += left*i;
            else if (mid == 1) res += right+1 + left*i;
            else res += (left+1)*i;
            if (n/10 < i) break;
        }
        return res;
    }
};