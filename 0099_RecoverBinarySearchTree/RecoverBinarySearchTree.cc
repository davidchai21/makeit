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
    void recoverTree(TreeNode* root) {
        TreeNode* low = nullptr;
        TreeNode* high = nullptr;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        helper(cur, pre, low, high);
        swap(low->val, high->val);
    }
private:
    void helper(TreeNode* root, TreeNode*& pre, TreeNode*& low, TreeNode*& high) {
        if (!root) return;
        helper(root->left, pre, low, high);
        if (pre && pre->val > root->val) {
            if (!low) low = pre;
            high = root;
        }
        pre = root;
        helper(root->right, pre, low, high);
    }
};