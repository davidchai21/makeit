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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int count = 0;
        TreeNode* res = helper(root, p, q, count);
        return count == 2 ? res : nullptr;
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, int& count) {
        if (!root) return nullptr;
        TreeNode* left = helper(root->left, p, q, count);
        TreeNode* right = helper(root->right, p, q, count);
        if (left && right) return root;
        if (root == q || root == p) {
            ++count;
            return root;
        }
        return left ? left : right ? right : nullptr;
    }
};