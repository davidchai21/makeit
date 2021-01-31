class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for (int i=0;i<nums.size();++i) {
            if (nums[i]%2) nums[i] *= 2;
        }
        set<int> s(nums.begin(), nums.end());
        
        int res = INT_MAX;
        for (;;) {
            int m = *s.rbegin();
            res = min(res, m-*s.begin());
            if (m%2) break;
            s.erase(m);
            s.insert(m/2);
        }
        return res;
    }
};