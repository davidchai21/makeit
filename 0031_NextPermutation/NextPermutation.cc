class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), right=0, left=0;
        for (left=n-1;left>0;--left) {
            if (nums[left-1]<nums[left]) break;
        }
        if (!left) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (right=left--;right<n;++right) {
            if (nums[right]<=nums[left]) break;
        }
        swap(nums[left], nums[--right]);
        sort(nums.begin()+left+1, nums.end());
    }
};