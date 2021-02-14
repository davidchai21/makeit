class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum+S)%2) return 0;
        return helper(nums, (sum+S)>>1);
    }
private:
    int helper(vector<int>& nums, int S) {
        vector<int> res(S+1, 0);
        res[0] = 1;
        for (int& num : nums) {
            for (int i=S;i>=num;--i) {
                res[i] += res[i-num];
            }
        }
        return res[S];
    }
};