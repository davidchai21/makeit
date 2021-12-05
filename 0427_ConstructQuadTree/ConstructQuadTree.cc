/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size()-1, grid.size()-1).first;
    }
private:
    pair<Node*, int> helper(vector<vector<int>>& grid, int x0, int y0, int x1, int y1) {
        if (x0 == x1) {
            bool val = grid[x0][y0]==1;
            return {new Node(val, true), val};
        }
        
        int mid_x = (x0+x1)/2;
        int mid_y = (y0+y1)/2;
        pair<Node*, int> topLeft = helper(grid, x0, y0, mid_x, mid_y);
        pair<Node*, int> topRight = helper(grid, x0, mid_y+1, mid_x, y1);
        pair<Node*, int> bottomLeft = helper(grid, mid_x+1, y0, x1, mid_y);
        pair<Node*, int> bottomRight = helper(grid, mid_x+1, mid_y+1, x1, y1);
        int val = 2;
        if (topLeft.second == 1 && topRight.second == 1 && bottomLeft.second == 1 && bottomRight.second == 1) val = 1;
        else if (topLeft.second == 0 && topRight.second == 0 && bottomLeft.second == 0 && bottomRight.second == 0) val = 0;
        if (val != 2) {
            return {new Node(val, true), val};
        }
        return {new Node(false, false, topLeft.first, topRight.first, bottomLeft.first, bottomRight.first), val};
    }
};