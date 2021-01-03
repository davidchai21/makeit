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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        int level = -1;
        helper(root, res, level, 0);
        return res;
    }
private:
    void helper(TreeNode* root, int& res, int& level, int l) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (level < l) {
                res = root->val;
                level = l;
            } else if (level == l) {
                res += root->val;
            }
            return;
        }
        helper(root->left, res, level, l+1);
        helper(root->right, res, level, l+1);
    }
};

// Iterative:

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q({root});
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            res = 0;
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                if (!cur->left && !cur->right) res += cur->val;
                else {
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }
            }
        }
        return res;
    }
};