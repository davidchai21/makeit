// O(n^2) space:

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> count(n, vector<bool>(n, false));
        int res = 0;
        for (int i=n-1;i>=0;--i) {
            for (int j=i;j<n;++j) {
                if (i == j) count[i][j] = true;
                else if (i+1 == j) count[i][j] = s[i] == s[j];
                else {
                    count[i][j] = s[i] == s[j] && count[i+1][j-1];
                }
                res += count[i][j];
            }
        }
        return res;
    }
};

// O(n) space:

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() < 2) return s.size();
        int n = s.size();
        vector<bool> record(n, false);
        record.back() = true;
        int res = 0;
        for (int i=n-1;i>=0;--i) {
            for (int j=n-1;j>=i;--j) {
                if (i==j) record[j] = true;
                else if (i+1==j) record[j] = s[i]==s[j];
                else {
                    record[j] = s[i] == s[j] && record[j-1];
                }
                res += record[j];
            }
        }
        return res;
    }
};
