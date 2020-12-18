class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        stack<int> st;
        int pre = INT_MIN;
        for (int i=0;i<preorder.size();++i) {
            if (st.empty() || st.top() > preorder[i]) {
                if (pre > preorder[i]) return false;
            } else {
                while (!st.empty() && st.top() < preorder[i]) {
                    pre = st.top();
                    st.pop();
                }
            }
            st.push(preorder[i]);
        }
        return true;
    }
};