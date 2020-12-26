// DFS:

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
    int maxDepth(Node* root) {
        if (!root) return 0;
        int d = 1;
        for (int i=0;i<root->children.size();++i) {
            d = max(d, maxDepth(root->children[i])+1);
        }
        return d;
    }
};

// BFS:

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
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;++i) {
                Node* cur = q.front();
                q.pop();
                for (int j=0;j<cur->children.size();++j) {
                    q.push(cur->children[j]);
                }
            }
            ++res;
        }
        return res;
    }
};