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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur) {
            pre = cur;
            if (cur->val > val) cur = cur->left;
            else cur = cur->right;
        }
        if (val > pre->val) pre->right = new TreeNode(val);
        else pre->left = new TreeNode(val);
        return root;
    }
};