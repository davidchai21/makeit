class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        if (n==1) return 1;
        int dis = -2;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front()/100;
                int y = q.front()%100;
                q.pop();
                if (x == n-1 && y==n-1) return -grid[x][y];
                for (pair<int,int>& d : dir) {
                    int _x = x+d.first;
                    int _y = y+d.second;
                    if (isValid(_x, _y, n) && grid[_x][_y] == 0) {
                        q.push(_x*100+_y);
                        grid[_x][_y] = dis;
                    }
                }
            }
            --dis;
        }
        return -1;
    }
private:
    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}, {1,1}, {-1,-1}, {1,-1}, {-1, 1}};
    
    inline bool isValid(int x, int y, int n) {
        return x>=0 && y>=0 && x<n && y<n;
    }
};