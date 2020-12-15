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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        helper(root, res);
        return res;
    }
private:
    int helper(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        int val = root->val+(left>0?left:0)+(right>0?right:0);
        res = max(res, val);
        val = max(left, right);
        return root->val+(val>0?val:0);
    }
};