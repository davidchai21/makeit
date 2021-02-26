class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        vector<int> st;
        int index = 0;
        for (int& num : pushed) {
            st.push_back(num);
            while (!st.empty() && st.back() == popped[index]) {
                st.pop_back();
                ++index;
            }
        }
        return st.empty();
    }
};