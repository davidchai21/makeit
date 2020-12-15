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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        helper(root, k, res);
        return res;
    }
private:
    void helper(TreeNode* root, int& k, int& res) {
        if (!root) return;
        helper(root->left, k, res);
        if (--k==0) res = root->val;
        helper(root->right, k, res);
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            helper(root, st);
            root = st.top();
            st.pop();
            if (!--k) return root->val;
            root = root->right;
        }
        return 0;
    }
private:
    void helper(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};