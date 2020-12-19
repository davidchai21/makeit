class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int res;
        int len = 1;
        for (int i=0;i<nums.size();++i) {
            if (target == nums[i]) {
                if (rand()%len == 0) res = i;
                ++len;
            }
        }
        return res;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */