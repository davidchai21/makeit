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
    int goodNodes(TreeNode* root) {
        int res = 0;
        helper(root, root->val, res);
        return res;
    }
private:
    void helper(TreeNode* root, int curMax, int& res) {
        if (!root) return;
        if (curMax <= root->val) {
            ++res;
            if (curMax < root->val) curMax = root->val;
        }
        helper(root->left, curMax, res);
        helper(root->right, curMax, res);
    }
};