class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k%(m*n);
        if (!k) return grid;
        shuffle(grid, 0, 0, m-1, n-1, m, n);
        int x1 = (k-1)/n;
        int y1 = (k-1)%n;
        int x0 = k/n;
        int y0 = k%n;
        shuffle(grid, 0, 0, x1, y1, m, n);
        shuffle(grid, x0, y0, m-1, n-1, m, n);
        return grid;
    }
private:
    void shuffle(vector<vector<int>>& grid, int x0, int y0, int x1, int y1, const int& m, const int& n) {
        while (x0 < x1 || x0 == x1 && y0 < y1) {
            swap(grid[x0][y0], grid[x1][y1]);
            if (y0 == n-1) {
                y0 = 0;
                ++x0;
            } else ++y0;
            if (y1 == 0) {
                y1 = n-1;
                --x1;
            } else --y1;
        }
    }
};