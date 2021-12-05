class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> table(size, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for (int k=0;k<size;++k) {
            int _m = 0, _n = 0;
            for (char& c : strs[k]) {
                if (c == '0') ++_m;
                else ++_n;
            }
            for (int i=0;i<=m;++i) {
                for (int j=0;j<=n;++j) {
                    if (k == 0) {
                        if (i>=_m && j>=_n) {
                            table[0][i][j] = 1;
                        }
                    } else {
                        if (i<_m || j<_n) table[k][i][j] = table[k-1][i][j];
                        else table[k][i][j] = max(table[k-1][i][j], table[k-1][i-_m][j-_n] + 1);
                    }
                }
            }
        }
        return table.back().back().back();
    }
};

// Better Space:

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> record(m+1, vector<int>(n+1, 0));
        for (int k=0;k<strs.size();++k) {
            int sm = 0, sn = 0;
            for (char& c : strs[k]) {
                if (c=='0') ++sm;
                else ++sn;
            }
            
            for (int i=m;i>=0;--i) {
                for (int j=n;j>=0;--j) {
                    if (i>=sm && j>=sn) {
                        record[i][j] = max(record[i-sm][j-sn]+1, record[i][j]);
                    } 
                }
            }
        }
        return record.back().back();
    }
};