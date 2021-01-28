class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -k-1;
        for (int i=0;i<nums.size();++i) {
            if (nums[i]) {
                if (i-pre<=k) return false;
                pre = i;
            }
        }
        return true;
    }
};