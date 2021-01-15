class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while (num) {
            if (num & 1) num &= num - 1;
            else num >>= 1;
            ++res;
        }
        return res;
    }
};

// built-in:

class Solution {
public:
    int numberOfSteps (int num) {
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};