/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        while (root && root != p) {
            if (root->val > p->val) {
                st.push(root);
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (!root) return root;
        if (root->right) {
            root = root->right;
            while (root->left) root = root->left;
            return root;
        }
        return st.empty() ? nullptr : st.top();
    }
};

// Shorter:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = nullptr;
        while (root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return res;
    }
};