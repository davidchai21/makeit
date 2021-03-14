class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        int left = 0, right = nums.size()-1;
        for (int i=0;i<=right;) {
            if (nums[i] == 0) {
                swap(nums[i++], nums[left++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right--]);
            } else {
                ++i;
            }
        }
    }
};