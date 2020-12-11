/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left) {
            TreeNode* tail = helper(root->left);
            TreeNode* right = root->right;
            root->right = root->left;
            root->left = nullptr;
            tail->right = right;
        }
    }
private:
    TreeNode* helper(TreeNode* root) {
        while (root->right) root = root->right;
        return root;
    } 
};

// Iterative:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left && root->right) {
                TreeNode* cur = root->left;
                while (cur->right) {
                    cur = cur->right;
                }
                cur->right = root->right;
            }
            if (root->left) {
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};