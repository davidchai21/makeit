class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int size = nums.size();
        int tail = 0;
        int res = 0;
        while (index < size) {
            int counter = 0;
            tail = index;
            while (tail<size && nums[tail] == nums[index]) {
                ++counter;
                ++tail;
            }
            for (int i = min(counter, 2);i>0;--i) {
                nums[res++] = nums[index];
            }
            index = tail;
        }
        return res;
    }
};