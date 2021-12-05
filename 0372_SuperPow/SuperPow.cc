class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a %= mod;
        int res = 1;
        for (int& k : b) {
            res = (getTen(res, 10)*getTen(a, k))%mod;
        }
        return res;
    }
private:
    const int mod = 1337;
    
    int getTen(int n, const int k) {
        if (k == 0) return 1;
        int res = n;
        for (int i=1;i<k;++i) {
            res = (res*n)%mod;
        }
        return res;
    }
};