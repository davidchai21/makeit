class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        while (index < n && nums[index]) ++index;
        for (int i=0;i<n;++i) {
            if (!nums[i]) {
                while (index < n && !nums[index]) ++index;
                if (index == n) return;
                swap(nums[i], nums[index]);
            }
        }
    }
};