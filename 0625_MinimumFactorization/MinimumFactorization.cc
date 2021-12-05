class Solution {
public:
    int smallestFactorization(int num) {
        if (num == 1) return 1;
        vector<int> record(10, 0);
        for (int i=2;i<8;++i) {
            while (num%i == 0) {
                num /= i;
                ++record[i];
            }
        }
        if (num != 1) return 0;
        
        while (record[2] >= 3) {
            record[2] -= 3;
            ++record[8];
        }
        while (record[3] >= 2) {
            record[3] -= 2;
            ++record[9];
        }
        while (record[2] && record[3]) {
            ++record[6];
            --record[2];
            --record[3];
        }
        if (record[2] == 2) {
            record[2] = 0;
            record[4] = 1;
        }
        
        int res = 0;
        for (int i=2;i<10;++i) {
            while (record[i]--) {
                if (INT_MAX/10 < res || INT_MAX/10 == res && i > 7) return 0;
                res = res*10+i;
            }
        }
        return res;
    }
};