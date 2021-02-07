class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() < 3) return true;
        int count = 0;
        for (int i=1;i<nums.size();++i) {
            if (nums[i-1] > nums[i]) ++count;
        }
        if (nums.back() > nums.front()) ++count;
        return count < 2;
    }
};