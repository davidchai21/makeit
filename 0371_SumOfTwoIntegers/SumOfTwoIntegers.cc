class Solution {
public:
    int getSum(int a, int b) {
        const long mask = 0xffffffff;
        while (b) {
            int ans = a^b;
            int carry = (a&b&mask)<<1;
            a = ans;
            b = carry;
        }
        return a;
    }
};