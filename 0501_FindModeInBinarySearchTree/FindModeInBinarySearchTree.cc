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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        int k = 0;
        int count = 0;
        int val = 0;
        helper(root, res, count, k, val);
        if (k==count) res.push_back(val);
        else if (k>count) {
            res.clear();
            res.push_back(val);
        }
        return res;
    }
private:
    void helper(TreeNode* root, vector<int>& res, int& count, int& k, int& val) {
        if (!root) return;
        helper(root->left, res, count, k, val);
        if (!k || val == root->val) ++k;
        else {
            if (k==count) {
                res.push_back(val);
            } else if (k>count) {
                res.clear();
                res.push_back(val);
                count = k;
            }
            k = 1;
        }
        val = root->val;
        helper(root->right, res, count, k, val);
    }
};