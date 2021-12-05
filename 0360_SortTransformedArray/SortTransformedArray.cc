class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res(n,c);
        if (a == 0) {
            if (b>0) {
                for (int i=0;i<n;++i) res[i] += b*nums[i];
            } else if (b<0) {
                for (int i=0;i<n;++i) res[i] += b*nums[n-1-i];
            }
        } else if (a < 0) {
            int left = 0, right = n-1;
            int index = 0;
            while (left <= right) {
                int l = f(nums[left], a, b, c);
                int r = f(nums[right], a, b, c);
                if (l < r) {
                    res[index++] = l;
                    ++left;
                } else {
                    res[index++] = r;
                    --right;
                }
            }
        } else {
            int right = helper(nums, -b/(2*a));
            int left = right-1;
            int index = 0;
            while (left >=0 && right < n) {
                int l = f(nums[left], a, b, c);
                int r = f(nums[right], a, b, c);
                if (l < r) {
                    res[index++] = l;
                    --left;
                } else {
                    res[index++] = r;
                    ++right;
                }
            }
            while (left >= 0) {
                res[index++] = f(nums[left--], a, b, c);
            }
            while (right < n) {
                res[index++] = f(nums[right++], a, b, c);
            }
        }
        return res;
    }
private:
    inline int f(int x, int a, int b, int c) {
        return a*x*x+b*x+c;
    }
    
    int helper(vector<int>& nums, const int target) {
        int left = 0, right = nums.size();
        while (left <= right) {
            int mid = (left+right)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};