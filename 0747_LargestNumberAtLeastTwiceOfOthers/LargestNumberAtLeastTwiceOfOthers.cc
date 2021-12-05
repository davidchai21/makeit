class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto s = max_element(nums.begin(), nums.end());
        for (int& num : nums) {
            if (num*2 > *s && num != *s) return -1;
        }
        return s-nums.begin();
    }
};

// One-pass:

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = nums.front(), second = -1;
        int index = 0;
        for (int i=1;i<nums.size();++i) {
            if (nums[i] > first) {
                second = first;
                first = nums[i];
                index = i;
            } else if (nums[i] > second) {
                second = nums[i];
            }
        }
        return first >= second*2 ? index : -1;
    }
};