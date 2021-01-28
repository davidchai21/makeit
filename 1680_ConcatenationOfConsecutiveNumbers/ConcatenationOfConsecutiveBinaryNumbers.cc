class Solution {
public:
    int concatenatedBinary(int n) {
        int res = 0;
        for (int i=1;i<=n;++i) add(res, i);
        return res;
    }
private:
    const int bound = 16;
    const int mod = 1e9+7;
    
    void add(int& res, int n) {
        bool flag = false;
        for (int i=bound;i>=0;--i) {
            int k = n & (1<<i) ? 1 : 0;
            if (flag) {
                res = ((res<<1)+k)%mod;
            } else {
                if (k) {
                    flag = true;
                    res = ((res<<1)+1)%mod;
                }
            }
        }
    }
};

// Using long:

class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 0L;
        for (int i=1;i<=n;++i) {
            int shift = 32-__builtin_clz(i);
            res = ((res<<shift)+i)%mod;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
};

// Using observation:

class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 0L;
        int shift = 0;
        for (int i=1;i<=n;++i) {
            if ((i & (i-1)) == 0) ++shift;
            res = ((res<<shift)+i)%mod;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
};