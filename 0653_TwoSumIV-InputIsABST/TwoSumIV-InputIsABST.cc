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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root, s, k);
    }
private:
    bool helper(TreeNode* root, unordered_set<int>& s, int k) {
        if (!root) return false;
        if (s.find(root->val) != s.end()) return true;
        s.insert(k-root->val);
        return helper(root->left, s, k) || helper(root->right, s, k);
    }
};