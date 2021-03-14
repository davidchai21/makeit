class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> cur(n, 1);
        for (int i=1;i<m;++i) {
            for (int j=1;j<n;++j) {
                cur[j] = cur[j-1]+prev[j];
            }
            prev.swap(cur);
        }
        return prev.back();
    }
};

// Shorter:

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(n, 1);
        for (int i=1;i<m;++i) {
            for (int j=1;j<n;++j) {
                res[j] += res[j-1];
            }
        }
        return res.back();
    }
};