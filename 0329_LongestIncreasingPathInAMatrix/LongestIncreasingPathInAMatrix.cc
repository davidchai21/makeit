class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> count(m, vector<int>(n, 0));
        int res = 1;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (!count[i][j]) res = max(res, helper(matrix, count, i, j, m, n));
            }
        }
        return res;
    }
private:
    bool isValid(int x, int y, const int& m, const int& n) {
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& count, int x, int y, const int& m, const int& n) {
        if (count[x][y]) return count[x][y];
        
        int res = 1;
        if (isValid(x+1, y, m, n) && matrix[x+1][y] < matrix[x][y]) res = max(res, 1+helper(matrix, count, x+1, y, m, n));
        if (isValid(x-1, y, m, n) && matrix[x-1][y] < matrix[x][y]) res = max(res, 1+helper(matrix, count, x-1, y, m, n));
        if (isValid(x, y+1, m, n) && matrix[x][y+1] < matrix[x][y]) res = max(res, 1+helper(matrix, count, x, y+1, m, n));
        if (isValid(x, y-1, m, n) && matrix[x][y-1] < matrix[x][y]) res = max(res, 1+helper(matrix, count, x, y-1, m, n));
        count[x][y] = res;
        return res;
    }
};