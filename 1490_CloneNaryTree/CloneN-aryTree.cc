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
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        Node* node = new Node(root->val);
        for (Node* child: root->children) {
            node->children.push_back(cloneTree(child));
        }
        return node;
    }
};

// Iterative:

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
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        unordered_map<Node*, Node*> m;
        m[root] = new Node(root->val);
        queue<Node*> q({root});
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* cur = q.front();
                q.pop();
                for (Node*& child: cur->children) {
                    Node* c = new Node(child->val);
                    m[child] = c;
                    m[cur]->children.push_back(c);
                    q.push(child);
                }
            }
        }
        return m[root];
    }
};