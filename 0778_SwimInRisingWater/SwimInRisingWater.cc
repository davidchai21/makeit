// Binary Search:

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = max(grid[0][0], grid.back().back());
        int right = n*n-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (helper(grid, mid, n)) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    vector<int> dir = {0, -1, 0, 1, 0};
    
    bool helper(vector<vector<int>>& grid, int h, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited.front().front() = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i=0;i<4;++i) {
                int _x = x+dir[i];
                int _y = y+dir[i+1];
                if (_x<0 || _y<0 || _x >= n || _y >= n || visited[_x][_y] || grid[_x][_y] > h) continue;
                if (_x == n-1 && _y == n-1) return true;
                visited[_x][_y] = true;
                q.push({_x, _y});
            }
        }
        return false;
    }
};

// Priority Queue:

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        const int diff = n*n;
        priority_queue<Node*, vector<Node*>, Comp> pq;
        pq.push(new Node(0,0,grid[0][0]));
        grid[0][0] -= diff;
        int res = grid[0][0];
        while (!pq.empty()) {
            Node* cur = pq.top();
            pq.pop();
            res = max(res, cur->val);
            if (cur->x == n-1 && cur->y == n-1) break;
            
            for (int i = 0;i<4;++i) {
                int _x = cur->x + dir[i];
                int _y = cur->y + dir[i+1];
                if (_x <0 || _y < 0 || _x >= n || _y >= n || grid[_x][_y] < 0) continue;
                pq.push(new Node(_x, _y, grid[_x][_y]));
                grid[_x][_y] -= diff;
            }
        }
        return res;
    }
private:
    vector<int> dir = {0, -1, 0, 1, 0};
    
    struct Node {
        int x, y, val;
        Node(int _x, int _y, int _val):x(_x), y(_y), val(_val) {}
    };
    
    struct Comp {
        bool operator() (const Node* lhs, const Node* rhs) {
            return lhs->val > rhs->val;
        }
    };
};