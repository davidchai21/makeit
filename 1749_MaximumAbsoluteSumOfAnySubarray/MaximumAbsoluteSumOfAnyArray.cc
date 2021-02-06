class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minVal = 0, maxVal = 0, minSum = 0, maxSum = 0;
        for (int& num : nums) {
            minSum += num;
            maxSum += num;
            if (maxSum < 0) maxSum = 0;
            else maxVal = max(maxVal, maxSum);
            if (minSum > 0) minSum = 0;
            else minVal = min(minVal, minSum);
        }
        return max(maxVal, -minVal);
    }
};