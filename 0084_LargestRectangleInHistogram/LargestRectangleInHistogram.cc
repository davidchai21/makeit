class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        for (int i=0;i<n;++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int index = st.empty() ? -1 : st.top();
                int area = h*(i-index-1);
                res = max(res, area);
            }
            st.push(i);
        }
        return res;
    }
};