class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int one = 0, two = 1;
        for (int i=2;i<=n;++i) {
            int s = one+two;
            one = two;
            two = s;
        }
        return two;
    }
};