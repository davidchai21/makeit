class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int index = 0;
        int n = nums.size();
        double sum = 0.0;
        while (index < k) {
            sum += nums[index++];
        }
        double res = sum/k;
        while (index < n) {
            sum += nums[index]-nums[index-k];
            ++index;
            res = max(sum/k, res);
        }
        return res;
    }
};