class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long> m;
        sort(arr.begin(), arr.end());
        long res = 0;
        for (int& num : arr) {
            long count = 1;
            for (auto it = m.begin(); it != m.end(); ++it) {
                if (num%it->first == 0) {
                    if (m.find(num/it->first) != m.end()) {
                        count += it->second * (m[num/it->first]);
                    }
                }
            }
            m[num] = count;
            res += count;
            res %= mod;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
};