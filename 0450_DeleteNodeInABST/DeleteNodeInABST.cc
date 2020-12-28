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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (!cur) return root;
        
        if (!pre) return helper(cur);
        if (pre->left == cur) pre->left = helper(cur);
        else pre->right = helper(cur);
        return root;
    }
private:
    TreeNode* helper(TreeNode* root) {
        if (!root->right) return root->left;
        TreeNode* res = root->right;
        TreeNode* cur = res;
        while (cur->left) cur = cur->left;
        cur->left = root->left;
        return res;
    }
};