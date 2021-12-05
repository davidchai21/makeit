class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& des) {
        if (start == des) return true;
        unordered_set<string> s;
        const int m = maze.size();
        const int n = maze[0].size();
        return dfs(maze, start[0], start[1], s, des, m, n);
    }
private:
    const vector<int> dir = {1, 0, -1, 0, 1};
    
    inline string getStr(int x, int y) {
        return to_string(x)+","+to_string(y);
    }
    
    bool dfs(vector<vector<int>>& maze, int x, int y, unordered_set<string>& s, const vector<int>& des, const int& m, const int& n) {
        if (s.find(getStr(x, y)) != s.end()) return false;
        if (x == des.front() && y == des.back()) return true;
        s.insert(getStr(x, y));
        
        for (int i=0;i<4;++i) {
            int _x = x, _y = y;
            while (_x >= 0 && _y >= 0 && _x<m && _y<n && maze[_x][_y]==0) {
                _x += dir[i];
                _y += dir[i+1];
            }
            _x -= dir[i];
            _y -= dir[i+1];
            if (dfs(maze, _x, _y, s, des, m, n)) return true;
        }
        return false;
    }
};