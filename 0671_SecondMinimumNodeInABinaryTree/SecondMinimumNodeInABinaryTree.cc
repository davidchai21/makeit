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
    int findSecondMinimumValue(TreeNode* root) {
        int last = -1;
        int second = -1;
        helper(root, last, second);
        return second;
    }
private:
    void helper(TreeNode* root, int& last, int& second) {
        if (!root) return;
        if (last == -1) last = root->val;
        else if (last == root->val) {}
        else if (last > root->val) {
            second = last;
            last = root->val;
        } else if (second == -1 || second > root->val) {
            second = root->val;
        }
        helper(root->left, last, second);
        helper(root->right, last, second);
    }
};