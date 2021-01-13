/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int diameter(Node* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    int helper(Node* root, int& res) {
        if (!root || root->children.empty()) return 0;
        int first = 0, second = 0;
        for (Node*& c : root->children) {
            int cur_len = helper(c, res)+1;
            if (cur_len > first) {
                second = first;
                first = cur_len;
            }
            else if (cur_len > second) second = cur_len;
        }
        res = max(first+second, res);
        return first;
    }
};