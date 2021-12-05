class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> record(m, vector<vector<int>>(n, vector<int>(N+1, -1)));
        return helper(record, i, j, m, n, N);
    }
private:
    const int mod = 1e9+7;
    
    int helper(vector<vector<vector<int>>>& record, int x, int y, int m, int n, int N) {
        if (x<0 || y<0 || x==m || y==n) return 1;
        if (!N) return 0;
        if (record[x][y][N] >= 0) return record[x][y][N];
        record[x][y][N] = ((helper(record, x, y+1, m, n, N-1) + helper(record, x, y-1, m, n, N-1))%mod + (helper(record, x+1, y, m, n, N-1) + helper(record, x-1, y, m, n, N-1))%mod)%mod;
        return record[x][y][N];
    }
};

// O(mn) space:

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        const int mod = 1e9+7;
        vector<vector<int>> dp(m, vector<int>(n, 0)), t(m, vector<int>(n, 0));
        for (;N>0;--N) {
            for (int x=0;x<m;++x) {
                for (int y=0;y<n;++y) {
                    t[x][y] = (((x==0 ? 1 : dp[x-1][y]) + (x==m-1 ? 1 : dp[x+1][y]))%mod + ((y==0 ? 1 : dp[x][y-1]) + (y==n-1 ? 1 : dp[x][y+1]))%mod)%mod;
                }
            }
            dp.swap(t);
        }
        return dp[i][j];
    }
};