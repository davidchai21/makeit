class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return 1;
        sort(nums.begin(), nums.end());
        int left = 0;
        long sum = 0;
        int res = 1;
        for (int i=1;i<n;++i) {
            sum += (long)(i-left)*(nums[i]-nums[i-1]);
            while (sum > k) {
                sum -= nums[i]-nums[left++];
            }
            res = max(res, i+1-left);
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        int left = 0, right = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (;right<n;++right) {
            k += nums[right];
            if (k < (long)nums[right]*(right+1-left)) {
                k -= nums[left++];
            }
        }
        return right-left;
    }
};