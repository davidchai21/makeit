class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1 || (n&(n-1))!=0) return false;
        while (n > 1) {
            n >>= 2;
        }
        return n==1;
    }
};

// Bit manipulation:

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1)) == 0 && n&base;
    }
private:
    const int base = 0x55555555;
};