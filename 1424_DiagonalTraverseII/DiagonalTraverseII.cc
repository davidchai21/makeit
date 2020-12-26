class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n =nums.size();
        vector<int> res;
        if (!n) return res;
        size_t m=0;
        for (int i=0;i<n;++i) m = max(m, nums[i].size());
        vector<vector<int>> t(m+n-1, vector<int>());
        for (int i=n-1;i>=0;--i) {
            for (int j=0;j<nums[i].size();++j) {
                t[i+j].push_back(nums[i][j]);
            }
        }
        for (int i=0;i<m+n-1;++i) {
            res.insert(res.end(), t[i].begin(), t[i].end());
        }
        return res;
    }
};