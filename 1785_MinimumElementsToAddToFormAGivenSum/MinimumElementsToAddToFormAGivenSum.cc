class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        long diff = abs((long)goal - sum);
        long res = diff/limit + (diff%limit ? 1 : 0);
        return res;
    }
};