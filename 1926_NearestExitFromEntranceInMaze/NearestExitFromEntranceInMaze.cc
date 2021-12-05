class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int base = 101;
        int res = 0;
        int m = maze.size(), n = maze.front().size();
        queue<int> q;
        q.push(entrance.front()*base+entrance.back());
        maze[entrance.front()][entrance.back()] = '+';
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int _x = q.front()/base;
                int _y = q.front()%base;
                q.pop();

                for (int i=0;i<4;++i) {
                    int x = _x + dir[i];
                    int y = _y + dir[i+1];
                    if (x<0 || y<0 || x>=m || y >= n) {
                        if (maze[_x][_y] == '*') return res;
                    } else if (maze[x][y] == '.') {
                        maze[x][y] = '*';
                        q.push(x*base+y);
                    }
                }
            }
            ++res;
        }
        return -1;
    }
private:
    vector<int> dir = {0, 1, 0, -1, 0};
};