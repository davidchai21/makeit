class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        for (int i=0;i<n-2;++i) {
            if (!nums[i]) continue;
            for (int j=i+1;j<n-1;++j) {
                int r = search(nums, j+1, nums[i]+nums[j]);
                res += r-j-1;
            }
        }
        return res;
    }
private:
    int search(vector<int>& nums, int left, int target) {
        int right = nums.size();
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid] >= target) right = mid;
            else left = mid+1;
        }
        return left;
    }
};

// Better: 

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i=0;i<n-2;++i) {
            if (!nums[i]) continue;
            for (int j=i+1, k=j+1;j<n-1;++j) {
                while (k < n && nums[k] < nums[i]+nums[j]) ++k;
                res += k-j-1;
            }
        }
        return res;
    }
};