class Solution {
public:
    int countGoodSubstrings(string s) {
        int res = 0;
        for (int i=s.size()-3;i>=0;--i) {
            if (helper(s.substr(i, 3))) ++res;
        }
        return res;
    }
private:
    bool helper(string s) {
        if (s[0] == s[1] || s[1] == s[2] || s[2] == s[0]) return false;
        return true;
    }
};