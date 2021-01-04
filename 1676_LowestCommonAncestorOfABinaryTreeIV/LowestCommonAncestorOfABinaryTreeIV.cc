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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> s;
        for (TreeNode*& node : nodes) s.insert(node);
        return helper(root, s);
    }
private:
    TreeNode* helper(TreeNode* root, unordered_set<TreeNode*>& s) {
        if (!root || s.find(root) != s.end()) return root;
        TreeNode* left = helper(root->left, s);
        TreeNode* right = helper(root->right, s);
        if (left && right) return root;
        return left ? left : right ? right : nullptr;
    }
};