class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int left = nums.front();
        int right = left;
        for (int i=1;i<nums.size();++i) {
            if (nums[i] != right+1) {
                if (left == right) res.push_back(to_string(left));
                else {
                    res.push_back(to_string(left)+"->"+to_string(right));
                }
                left = right = nums[i];
            } else {
                right = nums[i];
            }
        }
        if (left == right) res.push_back(to_string(left));
        else {
            res.push_back(to_string(left)+"->"+to_string(right));
        }
        return res;
    }
};