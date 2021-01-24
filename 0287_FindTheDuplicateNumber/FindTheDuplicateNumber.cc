class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums.front();
        int fast = slow;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        slow = nums.front();
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};