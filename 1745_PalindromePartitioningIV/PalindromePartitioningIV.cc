class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> record(n, vector<bool>(n, false));
        for (int i=n-1;i>=0;--i) {
            for (int j=i;j<n;++j) {
                if (i+1 >= j) record[i][j] = s[i]==s[j];
                else {
                    record[i][j] = s[i]==s[j] && record[i+1][j-1];
                }
            }
        }
        for (int i=0;i<n-2;++i) {
            if (record[0][i]) {
                for (int j=i+1;j<n-1;++j) {
                    if (record[i+1][j] && record[j+1][n-1]) return true;
                }
            }
        }
        return false;
    }
};