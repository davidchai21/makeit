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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        double diff = abs(root->val - target);
        helper(root, target, res, diff);
        return res;
    }
private:
    void helper(TreeNode* root, double target, int& res, double& diff) {
        if (!root) return;
        double newDiff = abs(root->val - target);
        if (newDiff < diff) {
            res = root->val;
            diff = newDiff;
        }
        if (root->val > target) helper(root->left, target, res, diff);
        else helper(root->right, target, res, diff);
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
    int closestValue(TreeNode* root, double target) {
        double diff = abs(root->val - target);
        int res = root->val;
        while (root) {
            double curDiff = abs(root->val - target);
            if (curDiff <= diff) {
                diff = curDiff;
                res = root->val;
            }
            if (root->val < target) root = root->right;
            else root = root->left;
        }
        return res;
    }
};