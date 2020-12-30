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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
private:
    pair<TreeNode*, int> helper(TreeNode* root) {
        if (!root) return make_pair(nullptr, 0);
        pair<TreeNode*, int> left = helper(root->left);
        pair<TreeNode*, int> right = helper(root->right);
        if (left.second == right.second) return make_pair(root, left.second+1);
        TreeNode* node = left.second > right.second ? left.first : right.first;
        int len = max(left.second, right.second) + 1;
        return make_pair(node, len);
    }
};