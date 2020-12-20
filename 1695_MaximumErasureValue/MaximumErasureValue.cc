class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        int sum = 0;
        for (int i=0, j=0;i<nums.size();++i) {
            if (!m[nums[i]]) {
                ++m[nums[i]];
                sum += nums[i];
                res = max(res, sum);
            } else {
                while (nums[j] != nums[i]) {
                    --m[nums[j]];
                    sum -= nums[j++];
                }
                ++j;
            }
        }
        return res;
    }
};