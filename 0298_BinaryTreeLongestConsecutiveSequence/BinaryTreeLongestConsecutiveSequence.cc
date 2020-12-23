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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    int helper(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        int len = 1;
        if (!root->left || root->left->val-1 == root->val) len = max(len, left+1);
        if (!root->right || root->right->val-1 == root->val) len = max(len, right+1);
        res = max(res, len);
        return len;
    }
};