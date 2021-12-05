class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        int base = 0;
        for (char& c : target) {
            if (c-'0' != base) {
                ++res;
                base = 1-base;
            }
        }
        return res;
    }
};