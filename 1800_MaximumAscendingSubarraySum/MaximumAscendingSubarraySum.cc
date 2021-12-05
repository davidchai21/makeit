class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int sum = nums.front();
        int left = nums.front();
        for (int i=1;i<nums.size();++i) {
            if (nums[i] > left) {
                sum += nums[i];
                left = nums[i];
            } else {
                res = max(res, sum);
                sum = nums[i];
                left = nums[i];
            }
        }
        res = max(res, sum);
        return res;
    }
};