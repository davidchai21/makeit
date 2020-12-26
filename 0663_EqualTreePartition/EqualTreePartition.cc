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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> m;
        int total = helper(root, m);
        if (!total) return m[total] > 1;
        return total%2==0 && m.find(total/2) != m.end();
    }
private:
    int helper(TreeNode* root, unordered_map<int, int>& m) {
        if (!root) return 0;
        int left = helper(root->left, m);
        int right = helper(root->right, m);
        int sum = left + root->val + right;
        ++m[sum];
        return sum;
    }
};