class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            int count = nums[mid]-nums.front()-mid;
            if (count >= k) right = mid;
            else left = mid;
        }
        if (nums[right]-nums.front()-right < k) return k + nums.front() + right;
        return k+nums.front()+left;
    }
};