class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> record(n+1, vector<int>(n+1, -1));
        return dfs(record, 1, n);
    }
private:
    int dfs(vector<vector<int>>& record, int left, int right) {
        if (record[left][right] != -1) return record[left][right];
        if (left == right) return record[left][right] = 0;
        if (left == right-1) return record[left][right] = min(left, right);
        
        int res = INT_MAX;
        for (int i=left+1;i<right;++i) {
            res = min(res, i+max(dfs(record, left, i-1), dfs(record, i+1, right)));
        }
        return record[left][right] = res;
    }
};

// Bottom-up:

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> record(n+1, vector<int>(n+1, 0));
        for (int j=2;j<=n;++j) {
            for (int i=j-1;i>0;--i) {
                if (i+1==j) record[i][j] = i;
                else {
                    int ans = INT_MAX;
                    for (int k=i+1;k<j;++k) {
                        ans = min(ans, k+max(record[i][k-1], record[k+1][j]));
                    }
                    record[i][j] = ans;
                }
            }
        }
        return record[1][n];
    }
};