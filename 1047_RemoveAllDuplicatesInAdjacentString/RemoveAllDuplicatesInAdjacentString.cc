class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (int i=0;i<S.size();++i) {
            if (st.empty() || st.top() != S[i]) {
                st.push(S[i]);
            } else {
                st.pop();
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Better:

class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for (int i=0;i<S.size();++i) {
            if (res.empty() || res.back()!=S[i]) res.push_back(S[i]);
            else res.pop_back();
        }
        return res;
    }
};