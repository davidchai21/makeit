class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> record(n, vector<bool>(n, false));
        int left = 0;
        int right = 0;
        for (int i=0;i<n;++i) {
            for (int j=i;j>=0;--j) {
                if (i <= j+1) record[j][i] = s[i]==s[j];
                else {
                    record[j][i] = s[i]==s[j] && record[j+1][i-1];
                }
                if (record[j][i] && i-j+1 > right-left) {
                    right = i;
                    left = j;
                }
            }
        }
        return s.substr(left, right-left+1);
    }
};