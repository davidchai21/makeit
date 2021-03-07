class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left + 1 < right) {
            int mid = left + (right - left)/2;
            if (nums[left] < nums[right]) left = right;
            else {
                if (nums[mid] >= nums[left]) left = mid;
                else right = mid-1;
            }
        }
        int tail = nums[right] > nums.front() ? right : left;
        return target >=nums.front() ? helper(nums, 0, tail, target) : helper(nums, tail+1, nums.size()-1, target);
    }
private:
    int helper(vector<int>& nums, int left, int right, const int& target) {
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return nums[right] == target ? right : -1;
    }
};

// Single Pass:

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) right = mid-1;
                else left = mid+1;
            } else {
                if (target > nums[mid] && target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};