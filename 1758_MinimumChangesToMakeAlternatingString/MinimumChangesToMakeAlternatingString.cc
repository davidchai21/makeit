class Solution {
public:
    int minOperations(string s) {
        return min(helper(s,0), helper(s,1));
    }
private:
    int helper(string& s, int start) {
        int res = 0;
        for (char& c : s) {
            if (c-'0' != start) ++res;
            start = 1 - start;
        }
        return res;
    }
};

// Better:

class Solution {
public:
    int minOperations(string s) {
        int res = 0, n = s.size();
        for (int i=0;i<n;++i) {
            if (s[i]-'0' == i%2) ++res;
        }
        return min(res, n-res);
    }
};