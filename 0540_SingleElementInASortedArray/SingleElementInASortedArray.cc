class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        
        int left = 0, right = (nums.size()-1)/2;
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid*2] != nums[mid*2+1]) right = mid;
            else left = mid+1;
        }
        return nums[left*2];
    }
};