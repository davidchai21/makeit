class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int bit = 0;
        while (num) {
            if (!(num&1)) {
                res |= 1<<bit;
            }
            ++bit;
            num >>= 1;
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int findComplement(int num) {
        int mask = num;
        mask |= (mask >> 1);
        mask |= (mask >> 2);
        mask |= (mask >> 4);
        mask |= (mask >> 8);
        mask |= (mask >> 16);
        return num^mask;
    }
};