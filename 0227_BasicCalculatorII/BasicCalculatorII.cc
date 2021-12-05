class Solution {
public:
    int calculate(string s) {
        s.push_back('+');
        stack<int> st;
        char sign = '+';
        int num = 0;
        for (char& c : s) {
            if (c == ' ') continue;
            else if (isdigit(c)) {
                num = num*10+(c-'0');
            } else {
                if (sign == '+' || sign == '-') {
                    num *= sign == '+' ? 1 : -1;
                    st.push(num);
                } else {
                    if (sign == '*') st.top() *= num;
                    else st.top() /= num;
                }
                num = 0;
                sign = c;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

// O(1) space:

class Solution {
public:
    int calculate(string s) {
        int last = 0, num = 0, res = 0;
        char sign = '+';
        s.push_back('+');
        for (char& c : s) {
            if (c == ' ') continue;
            if (isdigit(c)) {
                num = num*10+(c-'0');
            } else {
                if (sign == '+') {
                    res += last;
                    last = num;
                } else if (sign == '-') {
                    res += last;
                    last = -num;
                } else if (sign == '*') {
                    last *= num;
                } else {
                    last /= num;
                }
                num = 0;
                sign = c;
            }
        }
        return res + last;
    }
};