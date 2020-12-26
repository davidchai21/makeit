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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        processLeft(root->left, res, true);
        processRight(root->right, res, true);
        return res;
    }
private:
    void processLeft(TreeNode* root, vector<int>& res, bool flag) {
        if (!root) return;
        if (flag) {
            res.push_back(root->val);
            processLeft(root->left, res, true);
            processLeft(root->right, res, root->left?false:true);
        } else {
            if (!root->left && !root->right) res.push_back(root->val);
            else {
                processLeft(root->left, res, false);
                processLeft(root->right, res, false);
            }
        }
    }
    
    void processRight(TreeNode* root, vector<int>& res, bool flag) {
        if (!root) return;
        if (flag) {
            processRight(root->left, res, root->right?false:true);
            processRight(root->right, res, true);
            res.push_back(root->val);
        } else {
            if (!root->left && !root->right) res.push_back(root->val);
            else {
                processRight(root->left, res, false);
                processRight(root->right, res, false);
            }
        }
    }
};