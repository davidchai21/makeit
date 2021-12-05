class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        vector<long> res(10, 1L), t(10, 0L);
        res[5] = 0L;
        while (--n) {
            t[0] = (res[4]+res[6])%mod;
            t[1] = (res[6]+res[8])%mod;
            t[2] = (res[7]+res[9])%mod;
            t[3] = (res[4]+res[8])%mod;
            t[4] = (res[0]+res[3]+res[9])%mod;
            t[6] = (res[0]+res[1]+res[7])%mod;
            t[7] = (res[2]+res[6])%mod;
            t[8] = (res[1]+res[3])%mod;
            t[9] = (res[2]+res[4])%mod;
            
            res.swap(t);
        }
        return accumulate(res.begin(), res.end(), 0L)%mod;
    }
private:
    const int mod = 1e9+7;
};