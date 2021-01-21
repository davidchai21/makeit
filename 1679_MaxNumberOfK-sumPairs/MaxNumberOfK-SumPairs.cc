class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int& num : nums) ++m[num];
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second) {
                int left = k-it->first;
                if (m.find(left) != m.end() && m[left]) {
                    if (left != it->first) {
                        int k = min(m[left], it->second);
                        res += k;
                        m[left] -= k;
                        it->second -= k;
                    } else {
                        int k = it->second/2;
                        res += k;
                        it->second -= k;
                    }
                }
            }
        }
        return res;
    }
};