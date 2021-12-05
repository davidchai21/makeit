class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> small(n, 0), big(n, 1e6);
        big.front() = nums.front();
        for (int i=1;i<n;++i) {
            big[i] = max(nums[i], big[i-1]);
        }
        small.back() = nums.back();
        for (int i=n-2;i>=0;--i) {
            small[i] = min(small[i+1], nums[i]);
        }
        for (int i=0;i<n-1;++i) {
            if (big[i] <= small[i+1]) return i+1;
        }
        return 0;
    }
};

// O(1) space:

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int cur_max = nums.front();
        int left_max = cur_max;
        int index = 0;
        for (int i=1;i<nums.size();++i) {
            if (left_max > nums[i]) {
                left_max = cur_max;
                index = i;
            } else {
                cur_max = max(cur_max, nums[i]);
            }
        }
        return index+1;
    }
};