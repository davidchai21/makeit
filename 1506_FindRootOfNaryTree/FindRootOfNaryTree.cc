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
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node*, bool> m;
        for (Node*& node : tree) {
            if (m.find(node) == m.end()) m[node] = true;
            for (Node*& c : node->children) {
                m[c] = false;
            }
        }
        for (auto it = m.begin();it!=m.end();++it) {
            if (it->second) return it->first;
        }
        return nullptr;
    }
};

// O(1) space with Bit Manipulation:

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
    Node* findRoot(vector<Node*> tree) {
        int num = 0;
        for (Node*& node : tree) {
            num ^= node->val;
            for (Node*& c : node->children) {
                num ^= c->val;
            }
        }
        for (Node*& node : tree) {
            if (node->val == num) return node;
        }
        return nullptr;
    }
};

// Another long long solution:

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
    Node* findRoot(vector<Node*> tree) {
        long long res = 0LL;
        for (Node*& node : tree) {
            res ^= (long long) node;
            for (Node*& c : node->children) {
                res ^= (long long) c;
            }
        }
        return (Node*) res;
    }
};