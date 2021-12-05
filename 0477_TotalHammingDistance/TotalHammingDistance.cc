class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i=0;i<31;++i) {
            res += helper(nums, 1<<i);
        }
        return res;
    }
private:
    int helper(vector<int>& nums, int bit) {
        int count = 0;
        for (int& num : nums) {
            if (num&bit) ++count;
        }
        return count*(nums.size()-count);
    }
};