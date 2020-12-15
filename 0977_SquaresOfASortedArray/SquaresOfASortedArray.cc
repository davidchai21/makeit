class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int right = 0;
        int n = nums.size();
        vector<int> res(n);
        if (!n) return res;
        int index = 0;
        while (right < n && nums[right]<0) ++right;
        int left = right - 1;
        
        while (left>=0 && right<n) {
            if (nums[right]*nums[right]>nums[left]*nums[left]) {
                res[index++] = nums[left]*nums[left];
                --left;
            } else {
                res[index++] = nums[right]*nums[right];
                ++right;
            }
        }
        while (left>=0) {
            res[index++] = nums[left]*nums[left];
            --left;
        }
        while (right<n) {
            res[index++] = nums[right]*nums[right];
            ++right;
        }
        return res;
    }
};