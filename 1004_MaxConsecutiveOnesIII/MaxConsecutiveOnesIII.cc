class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, count = 0;
        int res = 0;
        for (int i=0;i<nums.size();++i) {
            if (!nums[i]) ++count;
            while (count > k) {
                if (!nums[left]) --count;
                ++left;
            }
            res = max(res, i+1-left);
        }
        return res;
    }
};

// queue:

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        q.push(-1);
        int res = 0;
        int n = nums.size();
        for (int i=0;i<n;++i) {
            if (!nums[i]) q.push(i);
            while (q.size() > k+1) {
                q.pop();
            }
            res = max(res, i-q.front());
        }
        return res;
    }
};

// Better:

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        for (;right<n;++right) {
            if (!nums[right]) --k;
            if (k<0) {
                if (!nums[left]) ++k;
                ++left;
            }
        }
        return right-left;
    }
};