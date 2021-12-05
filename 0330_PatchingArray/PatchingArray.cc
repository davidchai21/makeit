class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sum = 0;
        int res = 0;
        for (int& num : nums) {
            while (num > sum+1 && sum < n) {
                ++res;
                sum += sum+1;
            }
            sum += num;
            if (sum >= n) break;
        }
        while (sum < n) {
            ++res;
            sum += sum+1;
        }
        return res;
    }
};