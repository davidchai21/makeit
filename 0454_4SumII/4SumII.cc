class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int res = 0;
        if (!n) return res;
        unordered_map<int, int> m;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                ++m[-A[i]-B[j]];
            }
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                int sum = C[i]+D[j];
                if (m.find(sum) != m.end()) res += m[sum];
            }
        }
        return res;
    }
};