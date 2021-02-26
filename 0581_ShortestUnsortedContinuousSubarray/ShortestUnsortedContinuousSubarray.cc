// Sort

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums.begin(), nums.end());
        sort(copy.begin(), copy.end());
        int n = nums.size();
        int left = 0, right = n-1;
        while (left < n && nums[left] == copy[left]) ++left;
        if (left == n) return 0;
        while (right >= 0 && nums[right] == copy[right]) --right;
        return right-left+1;
    }
};

// Stack:

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> st;
        int left = n-1, right = 0;
        
        for (int i=0;i<n;++i) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                left = min(left, st.back());
                st.pop_back();
            }
            st.push_back(i);
        }
        if (left == n-1) return 0;
        
        st.clear();
        for (int i=n-1;i>=0;--i) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                right = max(right, st.back());
                st.pop_back();
            }
            st.push_back(i);
        }
        return right-left+1;
    }
};

// O(1) space:

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = n, right = -1;
        for (int i=1;i<n;++i) {
            if (nums[i] < nums[i-1]) {
                if (left == n) left = i-1;
                while (left >= 0 && nums[left] > nums[i]) --left;
            }
        }
        if (left == n) return 0;
        
        for (int i=n-2;i>=0;--i) {
            if (nums[i] > nums[i+1]) {
                if (right == -1) right = i+1;
                while (right < n && nums[right] < nums[i]) ++right;
            }
        }
        return right-left-1;
    }
};