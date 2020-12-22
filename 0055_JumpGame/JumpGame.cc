class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for (int i=0;i<=len && i<n; ++i) {
            len = max(i+nums[i], len);
            if (len >= n-1) return true;
        }
        return false;
    }
};