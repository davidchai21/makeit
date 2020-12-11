class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        int index = 0;
        int tail = 0;
        while (index < size) {
            tail = index;
            while (tail+1<size && nums[tail+1]==nums[index]) ++tail;
            nums[res++] = nums[index];
            index = tail+1;
        }
        return res;
    }
};

// Simpler:

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        for (int i=0;i<nums.size();++i) {
            if (nums[i]!=nums[res]) {
                nums[++res] = nums[i];
            }
        }
        return res + 1;
    }
};