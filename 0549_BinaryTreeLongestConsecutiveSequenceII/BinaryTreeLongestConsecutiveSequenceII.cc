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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    pair<int,int> helper(TreeNode* root, int& res) {
        if (!root) return make_pair(0,0);
        pair<int,int> left = helper(root->left, res);
        pair<int,int> right = helper(root->right, res);
        int up = 1, down = 1;
        if (!root->left || root->left->val+1 == root->val) up = max(up, left.first+1);
        if (!root->right || root->right->val+1 == root->val) up = max(up, right.first+1);
        if (!root->left || root->left->val-1 == root->val) down = max(down, left.second+1);
        if (!root->right || root->right->val-1 == root->val) down = max(down, right.second+1);
        res = max(res, max(up, down));
        int concat = 1;
        if ((!root->left || root->left->val+1 == root->val) && (!root->right || root->right->val-1 == root->val)) concat = max(concat, left.first + 1 + right.second);
        if ((!root->left || root->left->val-1 == root->val) && (!root->right || root->right->val+1 == root->val)) concat = max(concat, left.second + 1 + right.first);
        res = max(res, concat);
        return make_pair(up, down);
    }
};