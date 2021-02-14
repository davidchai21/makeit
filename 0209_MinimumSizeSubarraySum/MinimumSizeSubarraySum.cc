class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int n = nums.size();
        int res = n;
        for (int right = 0; right<n; ++right) {
            sum += nums[right];
            if (sum >= target) {
                while (left <= right && sum >= target) {
                    sum -= nums[left++];
                }
                res = min(res, right-left+2);
            }
        }
        return sum < target && !left ? 0 : res;
    }
};

// binary search:

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sums(nums.size()+1,0);
        for (int i=1;i<=nums.size();++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        if (sums.back() < target) return 0;
        
        int res = nums.size();
        for (int i = 1; i<sums.size();++i) {
            int left = 0, right = i;
            while (left + 1 < right) {
                int mid = left + (right-left)/2;
                if (sums[i]-sums[mid] < target) right = mid;
                else left = mid;
            }
            if (sums[i] - sums[left] >= target) {
                if (sums[i] - sums[right] >= target) res = min(res, i-right);
                else res = min(res, i-left);
            }
        }
        return res;
    }
};