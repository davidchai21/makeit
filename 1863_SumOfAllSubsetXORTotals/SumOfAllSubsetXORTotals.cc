class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = pow(2, nums.size());
        int res = 0;
        for (int i=1;i<n;++i) {
            res += helper(nums, i);
        }
        return res;
    }
private:
    int helper(vector<int>& nums, int k) {
        int res = 0;
        int index = nums.size()-1;
        while (k) {
            if (k&1) res ^= nums[index];
            k >>= 1;
            --index;
        }
        return res;
    }
};