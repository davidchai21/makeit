class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        priority_queue<Node*, vector<Node*>, Comp> pq;
        pq.push(new Node(0, 0, A.front().front()));
        int max_score = A[0][0];
        
        while (!pq.empty()) {
            Node* cur = pq.top();
            pq.pop();
            
            max_score = min(max_score, cur->val);
            if (cur->x == m-1 && cur->y == n-1) break;
            
            for (int i=0;i<4;++i) {
                int newx = cur->x+dir[i];
                int newy = cur->y+dir[i+1];
                if (newx >= 0 && newy >= 0 && newx < m && newy < n && A[newx][newy] >= 0) {
                    pq.push(new Node(newx, newy, A[newx][newy]));
                    A[newx][newy] = -1;
                }
            }
        }
        return max_score;
    }
private:
    vector<int> dir = {0, 1, 0, -1, 0};
    
    struct Node {
        int x, y;
        int val;
        
        Node(int _x, int _y, int _val): x(_x), y(_y), val(_val) {}
    };
    
    struct Comp {
        bool operator() (const Node* lhs, const Node* rhs) {
            return lhs->val < rhs->val;
        }
    };
};