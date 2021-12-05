class Solution {
public:
    int calculate(string s) {
        stack<long> st;
        stack<int> mark;
        mark.push(1);
        long num = 0;
        int curMark = 1;
        for (char& c : s) {
            if (c == ' ') continue;
            else if (isdigit(c)) {
                num = num*10+(c-'0');
            } else if (c == '+') {
                st.push(curMark*mark.top()*num);
                num = 0;
                curMark = 1;
            } else if (c == '-') {
                st.push(curMark*mark.top()*num);
                num = 0;
                curMark = -1;
            } else if (c == '(') {
                mark.push(curMark*mark.top());
                curMark = 1;
            } else {
                st.push(curMark*mark.top()*num);
                num = 0;
                mark.pop();
                curMark = 1;
            }
        }
        int res = curMark*mark.top()*num;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

// Another:

class Solution {
public:
    int calculate(string s) {
        stack<long> st;
        int result = 0;
        long num = 0;
        int sign = 1;
        for (char& c : s) {
            if (c == ' ') continue;
            else if (isdigit(c)) {
                num = num*10 + (c-'0');
            } else if (c == '+') {
                result += num*sign;
                sign = 1;
                num = 0;
            } else if (c == '-') {
                result += num*sign;
                sign = -1;
                num = 0;
            } else if (c == '(') {
                st.push(result);
                result = 0;
                st.push(sign);
                sign = 1;
            } else {
                result += num*sign;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
                sign = 1;
                num = 0;
            }
        }
        return result + sign*num;
    }
};