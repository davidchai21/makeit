class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i=nums.size()-2;i>=0;--i) {
            res = max(res, nums[i+1]-nums[i]);
        }
        return res;
    }
};

// Radix Sort:

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        vector<vector<int>> res(10);
        int mx = *max_element(nums.begin(), nums.end());
        long base = 1L;
        while (mx/base) {
            res.clear();
            res.resize(10);
            
            for (int & num : nums) {
                res[(num/base)%10].push_back(num);
            }
            
            int index = 0;
            for (int i=0;i<10;++i) {
                for (int & num : res[i]) {
                    nums[index++] = num;
                }
            }
            
            base *= 10L;
        }
        
        int ans = 0;
        for (int i=nums.size()-2;i>=0;--i) {
            ans = max(ans, nums[i+1]-nums[i]);
        }
        return ans;
    }
};