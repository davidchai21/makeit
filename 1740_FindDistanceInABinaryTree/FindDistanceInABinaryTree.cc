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
    int findDistance(TreeNode* root, int p, int q) {
        if (p == q) return 0;
        TreeNode* ancestor = helper(root, p, q);
        return sum(ancestor, p) + sum(ancestor, q);
    }
private:
    TreeNode* helper(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) return root;
        TreeNode* left = helper(root->left, p, q);
        TreeNode* right = helper(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
    
    int sum(TreeNode* root, int val) {
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->val == val) return depth;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ++depth;
        }
        return -1;
    }
};