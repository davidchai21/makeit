class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        n &= n-1;
        return !n;
    }
};