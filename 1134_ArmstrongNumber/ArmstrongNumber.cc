class Solution {
public:
    bool isArmstrong(int n) {
        int sum = 0;
        int k = getDigit(n);
        int save = n;
        while (n) {
            int d = n%10;
            sum += pow(d, k);
            n /= 10;
        }
        return sum == save;
    }
private:
    inline int getDigit(int n) {
        int res = 0;
        while (n) {
            ++res;
            n /= 10;
        }
        return res;
    }
};