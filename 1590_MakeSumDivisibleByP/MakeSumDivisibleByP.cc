class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int r = accumulate(nums.begin(), nums.end(), 0L)%p;
        if (!r) return 0;
        
        unordered_map<int, int> m;
        m[0] = -1;
        int n = nums.size();
        int sum = 0;
        int res = n;
        for (int i=0;i<n;++i) {
            sum = (sum+nums[i])%p;
            int left = (sum+p-r)%p;
            if (m.find(left) != m.end()) {
                res = min(res, i-m[left]);
            }
            m[sum] = i;
        }
        return res == n ? -1 : res;
    }
};