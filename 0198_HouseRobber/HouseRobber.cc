class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums.back();
        if (n == 2) return max(nums.front(), nums.back());
        int first = nums[0];
        int second = nums[1];
        int third = nums[2]+nums[0];
        for (int i=3;i<n;++i) {
            int k = nums[i] + max(first, second);
            first = second;
            second = third;
            third = k;
        }
        return max(second, third);
    }
};

// Shorter: 
// cur -> current max profit, pre->last max profit

class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0;
        int pre = 0;
        for (int& num:nums) {
            int t = num+pre;
            pre = cur;
            cur = max(cur, t);
        }
        return cur;
    }
};