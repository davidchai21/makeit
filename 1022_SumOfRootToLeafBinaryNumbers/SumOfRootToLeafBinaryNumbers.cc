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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        helper(root, 0, res);
        return res;
    }
private:
    void helper(TreeNode* root, int pre, int& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res += pre*2 + root->val;
            return;
        }
        pre = pre*2 + root->val;
        helper(root->left, pre, res);
        helper(root->right, pre, res);
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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 0));
        while (!st.empty()) {
            pair<TreeNode*, int> cur = st.top();
            st.pop();
            if (cur.first) {
                int num = cur.second*2 | cur.first->val;
                if (!cur.first->left && !cur.first->right) res += num;
                else {
                    st.push(make_pair(cur.first->right, num));
                    st.push(make_pair(cur.first->left, num));
                }
            }
        }
        return res;
    }
};