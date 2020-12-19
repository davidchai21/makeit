// O(n^2):

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> record(n,1);
        int res = 1;
        for (int i=1;i<n;++i) {
            int t = 1;
            for (int j=0;j<i;++j) {
                if (nums[i]>nums[j]) t = max(t, record[j]+1);
            }
            record[i] = t;
            res = max(res, t);
        }
        return res;
    }
};

// O(nlogn):

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i=0;i<nums.size();++i) {
            vector<int>::iterator it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};