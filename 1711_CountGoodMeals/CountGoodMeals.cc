class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> m;
        int maxD = -1;
        for (int& d : deliciousness) {
            maxD = max(maxD, d);
            ++m[d];
        }
        maxD <<= 1;
        int sum = 1;
        int res = 0;
        while (sum <= maxD) {
            long _sum = 0L;
            for (auto it = m.begin(); it != m.end(); ++it) {
                int r = sum - it->first;
                if (r<0 || m.find(r) == m.end()) continue;
                if (r == it->first) _sum += it->second*(it->second-1L);
                else _sum += (long)m[r]*it->second;
            }
            _sum = (_sum/2)%mod;
            res = (res+_sum)%mod;
            sum <<= 1;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
};