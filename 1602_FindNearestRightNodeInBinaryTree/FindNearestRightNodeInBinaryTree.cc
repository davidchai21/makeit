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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        TreeNode* res = nullptr;
        int level = -1;
        helper(root, u, 0, level, res);
        return res;
    }
private:
    void helper(TreeNode* root, TreeNode* u, int l, int& level, TreeNode* &res) {
        if (!root || res) return;
        if (level == l && !res) {
            res = root;
            return;
        }
        if (root == u) {
            level = l;
            return;
        }
        helper(root->left, u, l+1, level, res);
        helper(root->right, u, l+1, level, res);
    }
};

// Iterative: 

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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur == u) {
                    if (i == size-1) return nullptr;
                    else return q.front();
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return nullptr;
    }
};