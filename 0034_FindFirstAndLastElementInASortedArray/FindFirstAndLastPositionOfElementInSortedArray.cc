class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        if (nums.empty() || target < nums.front() || target > nums.back()) return res;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (nums[left] != target) return res;
        res[0] = left;
        
        left = 0, right = nums.size()-1;
        while (left+1 < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] <= target) left = mid;
            else right = mid-1;
        }
        if (nums[right] == target) res[1] = right;
        else res[1] = left;
        return res;
    }
};

// Lower_bound:

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        int left = lower_bound(nums, target);
        if (left >= nums.size() || nums[left] != target) return res;
        res[0] = left;
        res[1] = lower_bound(nums, target+1)-1;
        return res;
    }
private:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};