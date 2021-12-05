class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> nums(n);
        for (int i=0;i<n;++i) {
            nums[i] = nums1[i]-nums2[i];
        }
        sort(nums.begin(), nums.end());
        
        int left = 0, right = n-1;
        long long res = 0LL;
        while (left < right && nums[left]+nums[right] <= 0) ++left;
        while (left < n-1) {
            right = max(left+1, right);
            while (left < right && nums[left]+nums[right] > 0) --right;
            res += n - ++right;
            ++left;
        }
        return res;
    }
};