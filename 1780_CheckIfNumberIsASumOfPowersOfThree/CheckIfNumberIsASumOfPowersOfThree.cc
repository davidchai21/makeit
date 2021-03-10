class Solution {
public:
    bool checkPowersOfThree(int n) {
        int base = pow(3, 15);
        while (base) {
            if (n >= base) n -= base;
            base /= 3;
        }
        return !n;
    }
};

// Essence of this problem: 

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n%3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};