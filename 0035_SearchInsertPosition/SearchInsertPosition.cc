class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums.back()) return nums.size();
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid;
            else left = mid+1;
        }
        return left;
    }
};