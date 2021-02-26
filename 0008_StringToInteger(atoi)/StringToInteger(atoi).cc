class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int n = s.size();
        int res = 0;
        int mark = 1;
        while (index < n && s[index]==' ') ++index;
        if (s[index]=='-' || s[index]=='+') {
            mark = s[index] == '-' ? -1 : 1;
            ++index;
        }
        for (;index < n && isdigit(s[index]); ++index) {
            int cur = s[index]-'0';
            if (!res) {
                res += cur;
                if (res) res = mark*res;
            } else if (res < 0) {
                if (res < INT_MIN/10 || res == INT_MIN/10 && cur > 8) return INT_MIN;
                res = res*10-cur;
            } else {
                if (res > INT_MAX/10 || res == INT_MAX/10 && cur > 7) return INT_MAX;
                res = res*10+cur;
            }
        }
        return res;
    }
};