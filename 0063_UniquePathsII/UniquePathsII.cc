class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.front().front() || obstacleGrid.back().back()) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> res(n, 0);
        for (int i=0;i<n;++i) {
            if (obstacleGrid[0][i]) break;
            res[i] = 1;
        }
        for (int i=1;i<m;++i) {
            if (obstacleGrid[i][0]) res[0] = 0;
            for (int j=1;j<n;++j) {
                if (obstacleGrid[i][j]) res[j] = 0;
                else {
                    res[j] += res[j-1];
                }
            }
        }
        return res.back();
    }
};