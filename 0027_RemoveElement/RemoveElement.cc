class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left < right && nums[left] != val) ++left;
            while (left < right && nums[right] == val) --right;
            if (left >= right) break;
            swap(nums[left], nums[right]);
        }
        return nums[left] == val ? left : left + 1;
    }
};