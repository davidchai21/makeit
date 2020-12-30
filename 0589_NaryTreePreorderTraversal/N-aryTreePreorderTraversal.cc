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
    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
private:
    void helper(Node* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        for (Node*& node:root->children) {
            helper(node, res);
        }
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            for (int i=cur->children.size()-1;i>=0;--i) {
                st.push(cur->children[i]);
            }
        }
        return res;
    }
};