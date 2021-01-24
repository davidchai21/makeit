class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> col(n, 0);
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i=0;i<m;++i) {
            int sum = 0;
            for (int j=0;j<n;++j) {
                col[j] ^= matrix[i][j];
                sum ^= col[j];
                q.push(sum);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};