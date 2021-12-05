class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;
        int i=0;
        int n = nums.size();
        while (i<n && nums[i] == nums.front()) ++i;
        if (i == n) return res;
        
        bool up = nums[i] > nums.front() ? true : false;
        ++res;
        int pre = nums[i];
        while (i < n) {
            if (up) {
                while (i<n && nums[i] >= pre) {
                    pre = nums[i++];
                }
            } else {
                while (i<n && nums[i] <= pre) {
                    pre = nums[i++];
                }
            }
            if (i<n) {
                ++res;
                up = !up;
            }
        }
        return res;
    }
};