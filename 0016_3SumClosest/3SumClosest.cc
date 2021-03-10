class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0]+nums[1]+nums[2] >= target) return nums[0]+nums[1]+nums[2];
        if (nums[n-1]+nums[n-2]+nums[n-3] <= target) return nums[n-1]+nums[n-2]+nums[n-3];
        int res = nums[0]+nums[1]+nums[2];
        
        for (int i=0;i<nums.size()-2;++i) {
            int left = i+1, right = n-1;
            while (left < right) {
                int sum = nums[i]+nums[left]+nums[right];
                if (abs(res-target) > abs(sum-target)) res = sum;
                if (sum == target) return sum;
                else if (sum > target) {
                    int cur = nums[right];
                    while (left < right && cur == nums[right]) --right;
                } else {
                    int cur = nums[left];
                    while (left < right && cur == nums[left]) ++left;
                }
            }
        }
        return res;
    }
};