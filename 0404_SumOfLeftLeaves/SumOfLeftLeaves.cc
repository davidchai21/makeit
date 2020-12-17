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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode* root, int& res) {
        if (!root) return;
        if (isLeaf(root->left)) {res += root->left->val;}
        helper(root->left, res);
        helper(root->right, res);
    }
    bool isLeaf(TreeNode* root) {
        return root && !root->left && !root->right;
    }
};