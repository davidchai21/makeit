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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res, root);
        return res;
    }
private:
    void helper(vector<int>& res, TreeNode* root) {
        if (!root) return;
        helper(res, root->left);
        res.push_back(root->val);
        helper(res, root->right);
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        while (root) {
            st.push(root);
            root = root->left;
        }
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
        }
        return res;
    }
};

// Morris Traversal*:

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur=root, *pre;
        while (cur) {
            if (cur->left) {
                pre = cur->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = cur;
                TreeNode* t = cur->left;
                cur->left = nullptr;
                cur = t;
            } else {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};