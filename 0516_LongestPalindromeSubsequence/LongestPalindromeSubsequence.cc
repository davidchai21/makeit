class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> record(n, vector<int>(n, 0));
        int res = 0;
        for (int i=0;i<n;++i) {
            for (int j=i;j>=0;--j) {
                if (i==j) record[i][j] = 1;
                else if (j+1 == i) record[j][i] = s[i] == s[j] ? 2 : 1;
                else record[j][i] = max((s[i] == s[j] ? 2 : 0) + record[j+1][i-1], max(record[j+1][i], record[j][i-1]));
                res = max(res, record[j][i]);
            }
        }
        return res;
    }
};

// Better:

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> res(n, 0), t(n, 0);
        for (int i=0;i<n;++i) {
            for (int j=i;j>=0;--j) {
                if (i == j) t[i] = 1;
                else if (j+1 == i) t[j] = s[i] == s[j] ? 2 : 1;
                else t[j] = max((s[i] == s[j] ? 2 : 0) + res[j+1], max(res[j], t[j+1]));
            }
            res.swap(t);
        }
        return res.front();
    }
};