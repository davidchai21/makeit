class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int, int> m;
        for (int& a : arr) ++m[a];
        const int mod = 1e9+7;
        long res = 0L;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->first*3 > target) break;
            if (it->first*3 == target) {
                res += (long)it->second*(it->second-1)*(it->second-2)/6;
                break;
            }
            
            const int sum = target-it->first;
            for (auto iit = it; iit != m.end() && iit->first*2 <= sum; ++iit) {
                if (m.find(sum - iit->first) != m.end()) {
                    if (iit->first*2 == sum) {
                        res += (iit->second-1)*iit->second/2*it->second;
                    } else {
                        if (it == iit) {
                            res += it->second*(it->second-1)/2*m[sum-iit->first];
                        } else {
                            res += iit->second*m[sum-iit->first]*it->second;
                        }
                    }
                }
            }
            res %= mod;
        }
        return res%mod;
    }
};