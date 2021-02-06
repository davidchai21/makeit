class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num : nums) ++m[num];
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (m.find(it->first+1) != m.end()) {
                res = max(res, it->second + m[it->first+1]);
            }
        }
        return res;
    }
};