class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long res = 0L;
        for (int i=0;i<n;) {
            int j = i;
            int count = 0;
            while (j < n && nums[j] == nums[i]) {
                ++j, ++count;
            }
            res = (res + count*count)%mod;
            
            while (j < n) {
                int val = nums[j]/nums[i];
                int next = lower_bound(nums.begin()+j, nums.end(), (val+1)*nums[i]) - nums.begin();
                res = (res + val*count*(next-j))%mod;
                j = next;
            }
            i += count;
        }
        
        return res;
    }
private:
    static const int mod = 1e9+7;
};