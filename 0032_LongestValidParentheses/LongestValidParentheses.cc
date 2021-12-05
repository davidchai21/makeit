// DP:

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> record(n, 0);
        int res = 0;
        for (int i=1;i<n;++i) {
            if (s[i]==')') {
                if (s[i-1]=='(') {
                    record[i] = 2;
                    if (i-2>=0) record[i] += record[i-2];
                } else {
                    if (record[i-1]) {
                        int index = i-record[i-1]-1;
                        if (index>=0 && s[index] == '(') record[i] = 2+record[i-1]+(index > 0 ? record[index-1] : 0);
                    }
                }
                res = max(res, record[i]);
            }
        }
        return res;
    }
};

// stack:

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i=0;i<s.size();++i) {
            int t = st.top();
            if (t != -1 && s[i]==')' && s[t] == '(') {
                st.pop();
                res = max(res, i-st.top());
            } else {
                st.push(i);
            }
        }
        return res;
    }
};

// O(1) space: 

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int n = s.size();
        int res = 0;
        
        for (int i=0;i<n;++i) {
            s[i]=='(' ? ++left : ++right;
            if (left < right) {
                left = 0;
                right = 0;
            } else if (left == right) {
                res = max(res, left);
            }
        }
        
        left = 0, right = 0;
        for (int i=n-1;i>=0;--i) {
            s[i]=='(' ? ++left : ++right;
            if (left > right) {
                left = 0;
                right = 0;
            } else if (left == right) {
                res = max(left, res);
            }
        }
        return res*2;
    }
};