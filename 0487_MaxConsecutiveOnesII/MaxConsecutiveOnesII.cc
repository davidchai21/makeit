class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pre = 0, cur = 0, zero = 0;
        int n = nums.size();
        int index = 0;
        int res = 0;
        while (index < n) {
            int right = index;
            while (right < n && nums[right]) ++right;
            cur = right-index;
            if (zero==0) {
                res = max(res, cur+(right<n));
            } else if (zero == 1) {
                res = max(res, pre+cur+1);
            } else {
                res = max(res, cur+1);
            }
            zero = 0;
            while (right<n && nums[right]==0) {
                ++right;
                ++zero;
            }
            pre = cur;
            index = right;
        }
        return res;
    }
};

// One by one:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pre = 0, zero = 0, cur = 0;
        int res = 0, n = nums.size();
        for (int i=0;i<n;++i) {
            if (nums[i] == 1) {
                ++cur;
                if (zero == 0) res = max(cur, res);
                else if (zero == 1) res = max(cur+1+pre, res);
                else res = max(cur+1, res);
            } else {
                if (i && nums[i-1]==0) ++zero;
                else {
                    pre = cur;
                    cur = 0;
                    zero = 1;
                    res = max(res, 1+pre);
                }
            }
        }
        return res;
    }
};

// Two pointer:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, res = 0;
        int count = 0;
        int n = nums.size();
        for (int i=0;i<n;++i) {
            if (!nums[i]) ++count;
            while (count > 1) {
                if (nums[left] == 0) --count;
                ++left;
            }
            res = max(res, i+1-left);
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int one = 0, zero_one = 0;
        int res = 0;
        for (int& num : nums) {
            if (num) {
                ++one;
                ++zero_one;
            } else {
                zero_one = one+1;
                one = 0;
            }
            res = max(res, zero_one);
        }
        return res;
    }
};

// Another 2:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int k = 0;
        for (int& num : nums) {
            if (!num) ++k;
            if (k > 1 && nums[left++] == 0) {
                --k;
            }
        }
        return nums.size()-left;
    }
};