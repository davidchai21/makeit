class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        for (int left = 0, right = 1;right<nums.size();++right) {
            if (nums[right] <= nums[right-1]) {
                left = right;
            }
            res = max(res, right+1-left);
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int count = 1, res = 0;
        for (int i=1;i<n;++i) {
            if (nums[i] > nums[i-1]) ++count;
            else {
                res = max(count, res);
                count = 1;
            }
        }
        return max(res, count);
    }
};