class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums.front();
        int max_res = res;
        int min_res = res;
        for (int i=1;i<nums.size();++i) {
            int t = max(nums[i], max(nums[i]*max_res, nums[i]*min_res));
            min_res = min(nums[i], min(nums[i]*max_res, nums[i]*min_res));
            max_res = t;
            res = max(res, t);
        }
        return res;
    }
};

// Swap:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums.front();
        int max_res = res;
        int min_res = res;
        for (int i=1;i<nums.size();++i) {
            if (nums[i] < 0) swap(max_res, min_res);
            max_res = max(nums[i], max_res*nums[i]);
            min_res = min(nums[i], min_res*nums[i]);
            res = max(res, max_res);
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums.front();
        int n = nums.size();
        int l = 0, r = 0;
        for (int i=0;i<n;++i) {
            l = (l ? l : 1)*nums[i];
            r = (r ? r : 1)*nums[n-1-i];
            res = max(res, max(l, r));
        }
        return res;
    }
};