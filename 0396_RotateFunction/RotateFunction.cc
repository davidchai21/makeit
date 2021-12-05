class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long n = nums.size();
        long sum = 0L;
        long F = 0L;
        for (int i = 0;i<n;++i) {
            sum += nums[i];
            F += i*nums[i];
        }
        
        long res = F;
        int index = n-1;
        while (index>=0) {
            F += sum - n*nums[index--];
            res = max(res, F);
        }
        return res;
    }
};