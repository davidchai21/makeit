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
    bool isBalanced(TreeNode* root) {
        pair<int, bool> res = helper(root);
        return res.second;
    }
private:
    pair<int, bool> helper(TreeNode* root) {
        if (!root) return make_pair(0, true);
        pair<int, bool> l = helper(root->left);
        pair<int, bool> r = helper(root->right);
        if (!l.second || !r.second || abs(l.first-r.first)>1) return make_pair(-1, false);
        return make_pair(max(l.first, r.first)+1, true);
    }
};