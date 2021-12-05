class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int times = 1;
        int res = nums.front();
        for (int i=1;i<nums.size();++i) {
            if (res != nums[i]) {
                if (--times < 0) {
                    times = 1;
                    res = nums[i];
                }
            } else ++times;
        }
        return res;
    }
};