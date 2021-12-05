class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> res(5, 1);
        vector<long> t(5);
        for (int i=1;i<n;++i) {
            t[0] = (res[1]+res[2]+res[4])%mod;
            t[1] = (res[0]+res[2])%mod;
            t[2] = (res[1]+res[3])%mod;
            t[3] = (res[2])%mod;
            t[4] = (res[2]+res[3])%mod;
            res.swap(t);
        }
        return accumulate(res.begin(), res.end(), 0L)%mod;
    }
private:
    const int mod = 1e9+7;
};