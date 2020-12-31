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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        TreeNode* res = new TreeNode(root->val);
        if (root->children.empty()) return res;
        res->left = encode(root->children.front());
        TreeNode* cur = res->left;
        for (int i=1;i<root->children.size();++i) {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return res;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        Node* res = new Node(root->val);
        TreeNode* left = root->left;
        while (left) {
            res->children.push_back(decode(left));
            left = left->right;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));