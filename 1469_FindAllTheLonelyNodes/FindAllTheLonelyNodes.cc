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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode* root, vector<int>& res) {
        if (!root || !root->left && !root->right) return;
        if (!root->left || !root->right) {
            res.push_back(root->left?root->left->val:root->right->val);
        }
        helper(root->left, res);
        helper(root->right, res);
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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur->left) {
                st.push(cur->left);
                if (!cur->right) res.push_back(cur->left->val);
            }
            if (cur->right) {
                st.push(cur->right);
                if (!cur->left) res.push_back(cur->right->val);
            }
        }
        return res;
    }
};