class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long>> record(n+1, vector<long>(k+1, 0));
        return dfs(record, n, k);
    }
private:
    const int mod = 1e9+7;
    
    long dfs(vector<vector<long>>& record, int n, int k) {
        if (k > n || n <= 0 || k <= 0) return 0;
        if (k == n) return 1;
        if (record[n][k]) return record[n][k];
        
        return record[n][k] = (dfs(record, n-1, k-1)+dfs(record, n-1, k)*(n-1))%mod;
    }
};