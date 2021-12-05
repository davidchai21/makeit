class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int index = 0;
        for (;index<k-1;++index) ++m[nums[index]];
        int n = nums.size();
        vector<int> res(n-k+1);
        for (;index<n;++index) {
            ++m[nums[index]];
            res[index-k+1] = m.size();
            if (--m[nums[index-k+1]] == 0) {
                m.erase(nums[index-k+1]);
            }
        }
        return res;
    }
};