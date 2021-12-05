class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0, cur = 0;
        int res = 0;
        for (int i=0;i<s.size();++i) {
            if (i && s[i] != s[i-1]) {
                res += min(pre, cur);
                pre = cur;
                cur = 1;
            } else {
                ++cur;
            }
        }
        res += min(pre, cur);
        return res;
    }
};