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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return helper(root, sum);
    }
private:
    TreeNode* helper(TreeNode* root, int& sum) {
        if (!root) return nullptr;
        root->right = helper(root->right, sum);
        sum += root->val;
        root->val = sum;
        root->left = helper(root->left, sum);
        return root;
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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode* res = root;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->right;
            }
            root = st.top();
            st.pop();
            sum += root->val;
            root->val = sum;
            root = root->left;
        }
        return res;
    }
};