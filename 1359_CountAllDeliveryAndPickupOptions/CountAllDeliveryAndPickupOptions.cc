class Solution {
public:
    int countOrders(int n) {
        long res = 1;
        for (int i=2;i<=n;++i) {
            res = res*(2*i-1)*i % mod;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
};