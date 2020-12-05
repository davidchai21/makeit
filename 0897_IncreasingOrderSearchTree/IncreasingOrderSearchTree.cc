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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        helper(root);
        TreeNode* res = new TreeNode();
        TreeNode* cur = res;
        while (!s.empty()) {
            cur->right = s.top();
            cur = cur->right;
            cur->left = nullptr;
            s.pop();
        }
        cur = res->right;
        res->right = nullptr;
        delete res;
        return cur;
    }
private:
    stack<TreeNode*> s;
    void helper(TreeNode* root) {
        if (!root) return;
        helper(root->right);
        s.push(root);
        helper(root->left);
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
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root);
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* tail = nullptr) {
        if (!root) return tail;
        TreeNode* res = helper(root->left, root);
        root->left = nullptr;
        root->right = helper(root->right, tail);
        return res;
    }
};