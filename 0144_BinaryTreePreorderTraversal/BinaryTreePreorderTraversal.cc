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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
};

// iterative:

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (!root) {
                root = st.top()->right;
                st.pop();
            } else {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
        }
        return res;
    }
};

// Morris Traversal:

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (!root->left) {
                res.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* tail = root->left;
                while (tail->right && tail->right != root) tail = tail->right;
                if (tail->right) {
                    tail->right = nullptr;
                    root = root->right;
                } else {
                    tail->right = root;
                    res.push_back(root->val);
                    root = root->left;
                }
            }
        }
        return res;
    }
};