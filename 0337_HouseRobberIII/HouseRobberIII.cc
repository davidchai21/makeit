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
    int rob(TreeNode* root) {
        pair<int,int> res = helper(root);
        return res.first;
    }
private:
    pair<int,int> helper(TreeNode* root) {
        if (!root) return make_pair(0,0);
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        
        int second = left.first + right.first;
        int first = max(second, root->val+left.second+right.second);
        return make_pair(first, second);
    }
};