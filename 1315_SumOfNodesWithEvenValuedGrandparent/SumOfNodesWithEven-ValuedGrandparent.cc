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
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        helper(root, nullptr, nullptr, res);
        return res;
    }
private:
    void helper(TreeNode* root, TreeNode* pre, TreeNode* grandpa, int& res) {
        if (!root) return;
        if (grandpa && grandpa->val%2==0) res += root->val;
        helper(root->left, root, pre, res);
        helper(root->right, root, pre, res);
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
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->val%2==0) {
                if (cur->left) res += getVal(cur->left->left) + getVal(cur->left->right);
                if (cur->right) res += getVal(cur->right->left) + getVal(cur->right->right);
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return res;
    }
private:
    int getVal(TreeNode* node) {
        return node ? node->val : 0;
    }
};