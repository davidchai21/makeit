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
    double maximumAverageSubtree(TreeNode* root) {
        double res = 0.0;
        helper(root, res);
        return res;
    }
private:
    pair<int, int> helper(TreeNode* root, double& res) {
        if (!root) return make_pair(0,0);
        pair<int,int> left = helper(root->left, res);
        pair<int,int> right = helper(root->right, res);
        int val = root->val+left.first+right.first;
        int count = left.second+right.second+1;
        res = max(res, (double)val/count);
        return make_pair(val, count);
    }
};