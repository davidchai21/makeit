class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int left = 0, right = n-1;
        int sum = 0;
        while (left < n && sum + nums[left] <= x) {
            sum += nums[left++];
        }
        --left;
        while (right > left && sum + nums[right] <= x) {
            sum += nums[right--];
        }
        int res = -1;
        if (sum == x) res = left + n - right;
        while (left >= 0) {
            sum -= nums[left--];
            while (right > left && sum + nums[right] <= x) {
                sum += nums[right--];
            }
            if (sum == x && (res == -1 || res > left + n - right)) res = left + n - right;
        }
        return res;
    }
};