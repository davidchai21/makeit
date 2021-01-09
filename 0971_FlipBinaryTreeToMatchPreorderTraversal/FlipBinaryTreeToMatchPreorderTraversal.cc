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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int index = 0;
        bool flag = true;
        helper(root, voyage, index, flag, res);
        if (!flag || index < voyage.size()) return {-1};
        return res;
    }
private:
    void helper(TreeNode* root, vector<int>& voyage, int& index, bool& flag, vector<int>& res) {
        if (!root || !flag) return;
        if (root->val != voyage[index++]) {
            flag = false;
            return;
        }
        
        if (root->left && root->right) {
            if (index >= voyage.size()) {
                flag = false;
                return;
            }
            if (voyage[index] == root->right->val) {
                swap(root->left, root->right);
                res.push_back(root->val);
            }
        }
        helper(root->left, voyage, index, flag, res);
        helper(root->right, voyage, index, flag, res);
    }
};