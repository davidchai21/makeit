class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int base = nums.front();
        for (int i=1;i<nums.size();++i) {
            base = max(base+1, nums[i]);
            res += base-nums[i];
        }
        return res;
    }
};