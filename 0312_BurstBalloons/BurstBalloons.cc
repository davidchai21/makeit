// Recursive:

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size()+2;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> record(n, vector<int>(n,0));
        return helper(nums,1,n-2,record);
    }
private:
    int helper(vector<int>& nums, int left, int right, vector<vector<int>>& record) {
        if (left > right) return 0;
        if (record[left][right]) return record[left][right];
        int res = 0;
        for (int i=left;i<=right;++i) {
            res = max(res, nums[left-1]*nums[i]*nums[right+1]+helper(nums,left,i-1,record)+helper(nums,i+1,right,record));
        }
        record[left][right] = res;
        return res;
    }
};

// Iterative:

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size()+2;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> memo(n,vector<int>(n,0));
        
        for (int left = n-2;left>=0;--left) {
            for (int right = left+2;right<n;++right) {
                for (int i=left+1;i<right;++i) {
                    memo[left][right] = max(memo[left][right], nums[i]*nums[left]*nums[right]+memo[left][i]+memo[i][right]);
                }
            }
        }
        return memo[0][n-1];
    }
};