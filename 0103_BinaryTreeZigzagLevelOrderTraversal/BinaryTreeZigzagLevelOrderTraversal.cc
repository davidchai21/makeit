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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        bool flag = true;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> t(size);
            for (int i=0;i<size;++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                t[flag?i:size-i-1] = cur->val;
            }
            flag = !flag;
            res.push_back(t);
        }
        return res;
    }
};

// Recursive:

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        for (int i=1;i<res.size();i+=2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
private:
    void helper(TreeNode* root, vector<vector<int>>& res, int level) {
        if (!root) return;
        if (level>=res.size()) res.push_back(vector<int>());
        res[level].push_back(root->val);
        helper(root->left, res, level+1);
        helper(root->right, res, level+1);
    }
};