class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (!mid || nums[mid] > nums[mid-1]) {
                if (mid == n-1 || nums[mid] > nums[mid+1]) return mid;
                else left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

// Shorter:

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid] < nums[mid+1]) left = mid+1;
            else right = mid;
        }
        return left;
    }
};