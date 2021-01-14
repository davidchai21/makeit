/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        if (leaf == root) return root;
        Node* res = leaf;
        Node* parent = nullptr;
        while (leaf != root) {
            Node* op = leaf->parent;
            leaf->parent = parent;
            parent = leaf;
            if (leaf->left) leaf->right = leaf->left;
            leaf->left = op;
            if (op->left == leaf) op->left = nullptr;
            else op->right = nullptr;
            leaf = op;
        }
        leaf->parent = parent;
        return res;
    }
};