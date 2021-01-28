// Binary Search with BFS:

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 1e6;
        int m = heights.size();
        int n = heights[0].size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (helper(heights, mid, m, n)) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    vector<int> dir = {1,0,-1,0,1};
    
    bool helper(vector<vector<int>>& heights, int& mid, int m, int n) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x==m-1 && y==n-1) return true;
            
            for (int i = 0;i<4;++i) {
                int _x = x+dir[i];
                int _y = y+dir[i+1];
                if (isValid(_x, _y, m, n) && !visited[_x][_y] && abs(heights[_x][_y]-heights[x][y])<=mid) {
                    q.push(make_pair(_x, _y));
                    visited[_x][_y] = true;
                }
            }
        }
        return false;
    }
    
    inline bool isValid(int& x, int& y, int& m, int& n) {
        return x<m && x>=0 && y<n && y>=0;
    }
};

// Binary Search With DFS:

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 1e6;
        int m = heights.size();
        int n = heights[0].size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (helper(heights, mid, m, n)) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    vector<int> dir = {1,0,-1,0,1};
    
    bool helper(vector<vector<int>>& heights, int& mid, int m, int n) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        bool res = false;
        DFS(heights, visited, m, n, 0, 0, mid, res);
        return res;
    }
    
    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& visited, int& m, int& n, int x, int y, int& cap, bool& res) {
        if (res) return;
        if (x==m-1 && y==n-1) {
            res = true;
            return;
        }
        
        for (int i=0;i<4;++i) {
            int _x = x+dir[i];
            int _y = y+dir[i+1];
            if (isValid(_x, _y, m, n) && !visited[_x][_y] && abs(heights[x][y] - heights[_x][_y])<=cap) {
                visited[_x][_y] = true;
                DFS(heights, visited, m, n, _x, _y, cap, res);
            }
        }
    }
    
    inline bool isValid(int& x, int& y, int& m, int& n) {
        return x<m && x>=0 && y<n && y>=0;
    }
};

// Dijkstra Algorithm with Priority_queue:

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> record(m, vector<int>(n, INT_MAX));
        priority_queue<Node*, vector<Node*>, Comp> q;
        q.push(new Node(0,0,0));
        
        while (!q.empty()) {
            Node* cur = q.top();
            q.pop();
            if (cur->val >= record[cur->x][cur->y]) continue;
            record[cur->x][cur->y] = cur->val;
            
            for (int i=0;i<4;++i) {
                int x = cur->x + dir[i];
                int y = cur->y + dir[i+1];
                if (x<0 || y<0 || x>=m || y>=n) continue;
                int diff = abs(heights[x][y] - heights[cur->x][cur->y]);
                q.push(new Node(x, y, max(cur->val,diff)));
            }
        }
        return record[m-1][n-1];
    }
private:
    vector<int> dir = {1, 0, -1, 0, 1};
    
    struct Node {
        int x, y, val;
        Node(int _x, int _y, int _val):x(_x), y(_y), val(_val) {};
    };
    
    struct Comp {
        bool operator() (Node* a, Node* b) {
            return a->val > b->val;
        }
    };
};