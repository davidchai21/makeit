/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node* head = root;
        while (head->left) head = head->left;
        Node* pre = nullptr;
        helper(root, pre);
        pre->right = head;
        head->left = pre;
        return head;
    }
private:
    void helper(Node* root, Node*& pre) {
        if (!root) return;
        helper(root->left, pre);
        if (pre) pre->right = root;
        root->left = pre;
        pre = root;
        helper(root->right, pre);
    }
};

// Iterative:

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        stack<Node*> st;
        Node* pre = nullptr;
        Node* head = root;
        while (head->left) head = head->left;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            root->left = pre;
            if (pre) pre->right = root;
            pre = root;
            root = root->right;
        }
        pre->right = head;
        head->left = pre;
        return head;
    }
};