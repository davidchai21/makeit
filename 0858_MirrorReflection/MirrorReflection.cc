class Solution {
public:
    int mirrorReflection(int p, int q) {
        if (q == 0) return 0;
        int k = gcd(p, q);
        int a = p/k;
        int b = q/k;
        if ((a&1) && (b&1)) return 1;
        if ((a&1) && !(b&1)) return 0;
        if (!(a&1) && (b&1)) return 2;
        return -1;
    }
};