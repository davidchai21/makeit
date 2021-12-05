class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i=m-1;i>=0;--i) {
            for (int j=n-1;j>=0;--j) {
                if (A[i] != B[j]) dp[i][j] = 0;
                else {
                    if (i == m-1 || j == n-1) dp[i][j] = 1;
                    else dp[i][j] = 1+dp[i+1][j+1];
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

// O(n) space:

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int res = 0;
        vector<int> record(n+1, 0);
        for (int i=0;i<m;++i) {
            for (int j=n;j>0;--j) {
                if (A[i] == B[j-1]) {
                    record[j] = record[j-1]+1;
                    res = max(record[j], res);
                } else {
                    record[j] = 0;
                }
            }
        }
        return res;
    }
};