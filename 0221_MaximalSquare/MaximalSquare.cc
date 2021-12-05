class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> record(m+1, vector<int>(n+1, 0));
        
        int res = 0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (matrix[i][j] == '0') continue;
                record[i+1][j+1] = min(record[i][j], min(record[i][j+1], record[i+1][j])) + 1;
                res = max(res, record[i+1][j+1]);
            }
        }
        return res*res;
    }
};

// O(n) space:

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> cur(n+1, 0), t(n+1, 0);
        
        int res = 0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (matrix[i][j] == '0') t[j+1] = 0;
                else {
                    t[j+1] = min(t[j], min(cur[j], cur[j+1])) + 1;
                    res = max(res, t[j+1]);
                }
            }
            cur.swap(t);
        }
        return res*res;
    }
};

// use input matrix:

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        char res = 0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                int a = (i&&j) ? matrix[i-1][j-1] : 0;
                int b = i ? matrix[i-1][j] : 0;
                int c = j ? matrix[i][j-1] : 0;
                matrix[i][j] = matrix[i][j] == '1' ? min(a, min(b,c))+1 : 0;
                res = max(res, matrix[i][j]);
            }
        }
        return res*res;
    }
};