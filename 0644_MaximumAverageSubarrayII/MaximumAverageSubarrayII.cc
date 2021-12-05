class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int size = k*2;
        for (int i=1;i<n;++i) {
            nums[i] += nums[i-1];
        }
        double res = INT_MIN;
        for (int i=-1;i<n;++i) {
            for (int j=k;j<size && i+j < n;++j) {
                double sum = nums[i+j]-(i==-1 ? 0 : nums[i]);
                res = max(res, sum/j);
            }
        }
        return res;
    }
};