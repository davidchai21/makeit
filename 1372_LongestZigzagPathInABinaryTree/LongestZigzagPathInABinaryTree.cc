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
    int longestZigZag(TreeNode* root) {
        int res = 0;
        helper(root, 0, 0, res);
        return res;
    }
private:
    void helper(TreeNode* root, int left, int right, int& res) {
        if (!root) return;
        res = max(res, max(left, right));
        helper(root->left, right+1, 0, res);
        helper(root->right, 0, left+1, res);
    }
};