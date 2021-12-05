class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, m = s.size(), n = t.size();
        while (i < m && j < n) {
            while (j < n && t[j] != s[i]) ++j;
            if (j<n) {
                ++i;
                ++j;
            }
        }
        return i==m;
    }
};