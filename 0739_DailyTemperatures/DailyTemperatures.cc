class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n,0);
        stack<int> st;
        for (int i=0;i<n;++i) {
            while (!st.empty() && T[st.top()] < T[i]) {
                res[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};