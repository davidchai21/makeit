class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int res = nums.front();
        while (left <= right) {
            int mid = left+(right-left)/2;
            res = min(nums[mid], res);
            if (nums[mid] == nums[left]) ++left;
            else if (nums[mid] > nums[left]) {
                res = min(res, nums[left]);
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }
};