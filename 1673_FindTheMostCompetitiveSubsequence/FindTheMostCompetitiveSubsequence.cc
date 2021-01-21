class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i=0;i<n;++i) {
            int left = max(0, k+i-n);
            while (res.size() > left && res.back() > nums[i]) res.pop_back();
            res.push_back(nums[i]);
        }
        if (res.size() > k) res.resize(k);
        return res;
    }
};