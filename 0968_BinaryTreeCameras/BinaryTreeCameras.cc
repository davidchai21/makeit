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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        helper(root, res);
        if (!root->val) ++res;
        return res;
    }
private:
    void helper(TreeNode* root, int& res) {
        if (!root) return;
        helper(root->left, res);
        helper(root->right, res);
        int left = !root->left ? -1 : root->left->val;
        int right = !root->right ? -1 : root->right->val;
        if (!left || !right) {
            root->val = 1;
            ++res;
        }
        else if (left == 1 || right == 1) root->val = -1;
    }
};