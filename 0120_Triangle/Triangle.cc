class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=1;i<triangle.size();++i) {
            for (int j=0;j<triangle[i].size();++j) {
                if (j==0) triangle[i][j] += triangle[i-1][j];
                else if (j==triangle[i-1].size()) triangle[i][j] += triangle[i-1][j-1];
                else {
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                }
            }
        }
        int res = INT_MAX;
        for (int& k : triangle.back()) {
            res = min(res, k);
        }
        return res;
    }
};