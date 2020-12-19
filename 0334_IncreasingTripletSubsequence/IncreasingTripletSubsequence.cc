class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int small = 0;
        int mid = 0;
        for (int i=1;i<n;++i) {
            if (nums[i] <= nums[small]) small = i;
            else {
                if (!mid || nums[mid] >= nums[i]) mid = i;
                else return true;
            }
        }
        return false;
    }
};

// concise:

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX;
        int mid = INT_MAX;
        for (int i=0;i<nums.size();++i) {
            if (nums[i] <= small) small = nums[i];
            else if (nums[i] <= mid) mid = nums[i];
            else return true;
        }
        return false;
    }
};