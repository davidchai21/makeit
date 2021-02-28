class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;
        if (divisor == 1) return dividend;
        
        int res = 0;
        bool changeMark = false;
        if (dividend > 0) {
            dividend = -dividend;
            changeMark = !changeMark;
        }
        if (divisor > 0) {
            divisor = -divisor;
            changeMark = !changeMark;
        }
        
        int base = divisor;
        int bit = 1;
        while (base>=HALF && base+base>=dividend) {
            base += base;
            bit <<= 1;
        }
        
        while (dividend <= divisor) {
            if (dividend <= base) {
                res |= bit;
                dividend -= base;
            }
            base >>= 1;
            bit >>= 1;
        }
        return changeMark ? -res : res;
    }
private:
    const int HALF = INT_MIN/2;
};