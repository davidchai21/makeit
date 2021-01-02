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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) return node;
        if (root->val < val) {
            node->left = root;
            return node;
        }
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (cur) {
            st.push(cur);
            cur = cur->right;
        }
        TreeNode* child = nullptr;
        while (!st.empty() && st.top()->val < val) {
            child = st.top();
            st.pop();
        }
        st.top()->right = node;
        node->left = child;
        return root;
    }
};