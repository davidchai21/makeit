class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int odd = 1, even = 0;
        while (odd < n && even < n) {
            while (odd < n && nums[odd]%2) odd += 2;
            while (even < n && nums[even]%2==0) even += 2;
            if (odd >= n || even >= n) break;
            swap(nums[odd], nums[even]);
        }
        return nums;
    }
};