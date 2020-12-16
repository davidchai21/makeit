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
    int countUnivalSubtrees(TreeNode* root) {
        return helper(root).second;
    }
private:
    pair<bool, int> helper(TreeNode* root) {
        if (!root) return make_pair(true, 0);
        if (!root->left && !root->right) return make_pair(true, 1);
        pair<bool, int> left = helper(root->left);
        pair<bool, int> right = helper(root->right);
        if (root->left && root->right) return (left.first && right.first && root->val == root->left->val && root->val == root->right->val)?make_pair(true, left.second+right.second+1):make_pair(false,left.second+right.second);
        if (!root->left) return (right.first&&root->val == root->right->val)?make_pair(true, right.second+1):make_pair(false, right.second);
        if (!root->right) return (left.first&&root->val == root->left->val)?make_pair(true, left.second+1):make_pair(false, left.second);
        return make_pair(false, 0);
    }
};