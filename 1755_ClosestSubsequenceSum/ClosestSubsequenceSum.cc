class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int k = nums.size()/2;
        vector<int> left(nums.begin(), nums.begin()+k);
        vector<int> right(nums.begin()+k, nums.end());
        vector<int> a = generate(left);
        vector<int> b = generate(right);
        
        int res = INT_MAX;
        for (int& x : a) {
            int index = lower_bound(b.begin(), b.end(), goal-x) - b.begin();
            if (index) res = min(res, goal-x-b[index-1]);
            if (index < b.size()) res = min(res, x+b[index]-goal);
            if (!res) return 0;
        }
        return res;
    }
private:
    vector<int> generate(vector<int>& nums) {
        int k = nums.size();
        int n = 1<<k;
        vector<int> res(n, 0);
        for (int i=1;i<n;++i) {
            int sum = 0;
            for (int j=0;j<k;++j) {
                if (1<<j & i) sum += nums[j];
            }
            res[i] = sum;
        }
        sort(res.begin(), res.end());
        return res;
    }
};