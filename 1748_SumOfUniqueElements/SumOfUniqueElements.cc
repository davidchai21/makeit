class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int& num : nums) ++m[num];
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 1) res += it->first;
        }
        return res;
    }
};