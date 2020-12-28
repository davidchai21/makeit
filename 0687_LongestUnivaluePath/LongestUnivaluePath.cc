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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return max(0, res-1);
    }
private:
    int helper(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        int sum = 1;
        if (root->left && root->left->val == root->val) sum += left;
        if (root->right && root->right->val == root->val) sum += right;
        res = max(sum, res);
        sum = 1;
        if (root->left && root->left->val == root->val) sum += left;
        if (root->right && root->right->val == root->val) sum = max(sum, 1+right);
        return sum;
    }
};