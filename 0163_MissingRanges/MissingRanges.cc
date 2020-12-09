class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return {helper(lower, upper)};
        vector<string> res;
        int left = lower;
        for (int i=0;i<nums.size();++i) {
            if (left == nums[i]) {
                ++left;
                continue;
            }
            res.push_back(helper(left, nums[i]-1));
            left = nums[i]+1;
        }
        if (left <= upper) res.push_back(helper(left, upper));
        return res;
    }
private:
    string helper(int a, int b) {
        if (a==b) return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
};