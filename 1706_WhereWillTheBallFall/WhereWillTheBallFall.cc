class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size());
        for (int i=0;i<grid[0].size();++i) {
            res[i] = helper(grid, i);
        }
        return res;
    }
private:
    int helper(vector<vector<int>>& grid, int col) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0;i<m;++i) {
            if (grid[i][col]==1) {
                if (col >= n-1 || grid[i][col+1]==-1) return -1;
                ++col;
            } else {
                if (col <=0 || grid[i][col-1]==1) return -1;
                --col;
            }
        }
        return col;
    }
};