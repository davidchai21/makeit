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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> t(size);
            for (int i = 0;i<size;++i) {
                Node* cur = q.front();
                q.pop();
                t[i] = cur->val;
                for (int j=0;j<cur->children.size();++j) {
                    q.push(cur->children[j]);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};

// Recursive:

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        return res;
    }
private:
    void helper(Node* root, vector<vector<int>>& res, int level) {
        if (!root) return;
        if (level >= res.size()) res.push_back({});
        res[level].push_back(root->val);
        for (int i=0;i<root->children.size();++i) {
            helper(root->children[i], res, level+1);
        }
    }
};