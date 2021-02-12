class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (rooms[i][j] == 0) {
                    helper(rooms, i, j, m, n);
                }
            }
        }
    }
private:
    vector<int> dir = {1, 0, -1, 0, 1};
    
    void helper(vector<vector<int>>& rooms, int x, int y, int& m, int& n) {
        queue<pair<int,int>> q;
        int dis = 0;
        q.push(make_pair(x,y));
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                rooms[x][y] = dis;
                for (int i=0;i<4;++i) {
                    int _x = x+dir[i];
                    int _y = y+dir[i+1];
                    if (_x>=0 && _y>=0 && _x<m && _y<n && rooms[_x][_y] > dis) {
                        q.push(make_pair(_x, _y));
                    }
                }
            }
            ++dis;
        }
    }
};