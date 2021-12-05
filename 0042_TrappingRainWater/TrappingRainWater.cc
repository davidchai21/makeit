class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (!n) return 0;
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        for (int i=1;i<n;++i) {
            left[i] = max(left[i-1], height[i]);
        }
        right.back() = height.back();
        for (int i=n-2;i>=0;--i) {
            right[i] = max(right[i+1], height[i]);
        }
        
        int res = 0;
        for (int i=0;i<n;++i) {
            int h = min(left[i], right[i]);
            res += (h-height[i]);
        }
        return res;
    }
};

// Two pointers:

class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0, right_max = 0;
        int left = 0, right = height.size()-1;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);
                res += left_max-height[left++];
            } else {
                right_max = max(right_max, height[right]);
                res += right_max-height[right--];
            }
        }
        return res;
    }
};

// Stack:

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int i=0;i<height.size();++i) {
            while (!st.empty() && height[st.top()]<height[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                res += (min(height[st.top()], height[i])-height[top])*(i-1-st.top());
            }
            st.push(i);
        }
        return res;
    }
};