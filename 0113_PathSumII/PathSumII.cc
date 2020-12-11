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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> t;
        helper(res, t, root, sum);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int> t, TreeNode* root, int sum) {
        if (!root) return;
        if (root->val == sum && !root->left && !root->right) {
            t.push_back(root->val);
            res.push_back(t);
            return;
        }
        t.push_back(root->val);
        helper(res, t, root->left, sum-root->val);
        helper(res, t, root->right, sum-root->val);
    }
};

// Better:

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> t;
        helper(res, t, root, sum);
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& t, TreeNode* root, int sum) {
        if (!root) return;
        t.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) res.push_back(t);
        helper(res, t, root->left, sum-root->val);
        helper(res, t, root->right, sum-root->val);
        t.pop_back();
    }
};