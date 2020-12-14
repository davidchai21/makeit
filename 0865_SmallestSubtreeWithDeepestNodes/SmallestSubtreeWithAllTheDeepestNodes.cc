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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         return helper(root).second;
    }
private:
    pair<int, TreeNode*> helper(TreeNode* root) {
        if (!root) return make_pair(0, root);
        pair<int, TreeNode*> l = helper(root->left);
        pair<int, TreeNode*> r = helper(root->right);
        if (l.first == r.first) return make_pair(l.first+1, root);
        else if (l.first > r.first) return make_pair(l.first+1, l.second);
        return make_pair(r.first+1, r.second);
    }
};