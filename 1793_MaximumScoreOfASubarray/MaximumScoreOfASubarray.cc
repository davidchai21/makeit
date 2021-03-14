class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k;
        int n = nums.size();
        int res = 0;
        while (left >= 0 || right < n) {
            int value = left < 0 ? nums[right] : right >= n ? nums[left] : max(nums[left], nums[right]);
            while (left >= 0 && nums[left] >= value) --left;
            while (right < n && nums[right] >= value) ++right;
            res = max(res, (right-left-1)*value);
        }
        return res;
    }
};