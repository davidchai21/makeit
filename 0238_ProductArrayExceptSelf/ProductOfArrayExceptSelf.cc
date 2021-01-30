class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int pre = 1, post = 1;
        for (int i=1;i<n;++i) {
            pre *= nums[i-1];
            post *= nums[n-i];
            res[i] *= pre;
            res[n-1-i] *= post;
        }
        return res;
    }
};