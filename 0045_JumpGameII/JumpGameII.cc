class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 0;
        vector<int> res(n,-1);
        res.front() = 0;
        for (int i=0;i<n;++i) {
            if (n-1<=i+nums[i]) return res[i]+1;
            for (int j=min(n-1, i+nums[i]);j>i;--j) {
                if (res[j]==-1) res[j] = res[i]+1;
                else break;
            }
        }
        return res.back();
    }
};

// O(1) space:

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return 0;
        int maxPos = nums[0];
        int index = 0;
        int res = 1;
        while (index < n) {
            if (maxPos >= n-1) return res;
            int newPos = 0;
            for (int i=index+1;i<=maxPos && i<n;++i) {
                newPos = max(newPos, nums[i]+i);
            }
            index = maxPos;
            maxPos = newPos;
            ++res;
        }
        return res;
    }
};