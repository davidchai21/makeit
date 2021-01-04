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
    bool isValidSequence(TreeNode* root, vector<int>& arr, int index = 0) {
        if (!root) return false;
        if (index >= arr.size() || root->val != arr[index]) return false;
        if (index == arr.size()-1 && !root->left && !root->right) return true;
        return isValidSequence(root->left, arr, index+1) || isValidSequence(root->right, arr, index+1);
    }
};