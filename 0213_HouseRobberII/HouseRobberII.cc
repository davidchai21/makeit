class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n==1) return nums.back();
        return max(helper(nums,0,n-2), helper(nums,1,n-1));
    }
private:
    int helper(vector<int>& nums, int left, int right) {
        int cur = 0;
        int pre = 0;
        for (int i=left;i<=right;++i) {
            int t = max(cur, pre+nums[i]);
            pre = cur;
            cur = t;
        }
        return cur;
    }
};