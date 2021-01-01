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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root) return {nullptr, nullptr};
        if (root->val <= V) {
            vector<TreeNode*> right = splitBST(root->right, V);
            root->right = right[0];
            return {root, right[1]};
        } else {
            vector<TreeNode*> left = splitBST(root->left, V);
            root->left = left[1];
            return {left[0], root};
        }
        return {};
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res(2, nullptr);
        stack<TreeNode*> st;
        while (root) {
            st.push(root);
            if (root->val > V) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur->val > V) {
                cur->left = res[1];
                res[1] = cur;
            } else {
                cur->right = res[0];
                res[0] = cur;
            }
        }
        return res;
    }
};