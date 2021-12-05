class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;
        for (int& num : nums) {
            sum += num;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
};

// Divide and Conquer:

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1);
    }
private:
    int divide(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right-left)/2;
        int res = max(divide(nums, left, mid), divide(nums, mid+1, right));
        int l = INT_MIN, r = INT_MIN;
        int lsum = 0, rsum = 0;
        int index = mid;
        while (index >= left) {
            lsum += nums[index--];
            l = max(l, lsum);
        }
        index = mid+1;
        while (index <= right) {
            rsum += nums[index++];
            r = max(r, rsum);
        }
        return max(l+r, res);
    }
};