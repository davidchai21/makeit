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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s;
        for (int& i : to_delete) s.insert(i);
        helper(root, s, res, true);
        return res;
    }
private:
    TreeNode* helper(TreeNode* root, unordered_set<int>& s, vector<TreeNode*>& res, bool isRoot) {
        if (!root) return nullptr;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (s.find(root->val) != s.end()) {
            root->left = nullptr;
            root->right = nullptr;
            helper(left, s, res, true);
            helper(right, s, res, true);
            return nullptr;
        } else {
            if (isRoot) res.push_back(root);
            root->left = helper(left, s, res, false);
            root->right = helper(right, s, res, false);
            return root;
        }
    }
};