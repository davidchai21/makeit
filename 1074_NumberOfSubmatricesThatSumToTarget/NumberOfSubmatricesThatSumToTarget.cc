class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> record(n, 0);
        int res = 0;
        
        for (int i=0;i<m;++i) {
            fill(record.begin(), record.end(), 0);
            for (int j=i;j<m;++j) {
                for (int k=0;k<n;++k) {
                    record[k] += matrix[j][k];;
                }
                unordered_map<int, int> mp;
                ++mp[0];
                int sum = 0;
                for (int& k : record) {
                    sum += k;
                    if (mp.find(sum-target) != mp.end()) res += mp[sum - target];
                    ++mp[sum];
                }
            }
        }
        return res;
    }
};