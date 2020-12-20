class Solution {
public:
    string reformatNumber(string number) {
        stack<char> st;
        for (auto it = number.rbegin();it!=number.rend();++it) {
            if (isdigit(*it)) st.push(*it);
        }
        string res = "";
        while (st.size() > 4) {
            string part = "";
            for (int i=0;i<3;++i) {
                part += st.top();
                st.pop();
            }
            if (!res.empty()) res += '-';
            res.append(part);
        }
        if (!res.empty()) res += '-';
        if (st.size() != 4) {
            while (!st.empty()) {
                res += st.top();
                st.pop();
            }
        } else {
            res += st.top();
            st.pop();
            res += st.top();
            st.pop();
            res += '-';
            res += st.top();
            st.pop();
            res += st.top();
            st.pop();
        }
        return res;
    }
};