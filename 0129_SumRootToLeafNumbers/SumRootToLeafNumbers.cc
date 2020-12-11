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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, sum, 0);
        return sum;
    }
private:
    void helper(TreeNode* root, int& sum, int t) {
        if (!root) return;
        if (!root->left && !root->right) {
            sum += t*10+root->val;
            return;
        }
        helper(root->left, sum, t*10+root->val);
        helper(root->right, sum, t*10+root->val);
    }
};

// Better Recursive:

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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
private:
    int helper(TreeNode* root, int sum) {
        if (!root) return 0;
        if (!root->left && !root->right) return sum*10+root->val;
        return helper(root->left, sum*10+root->val) + helper(root->right, sum*10+root->val);
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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> cur = st.top();
            st.pop();
            if (!cur.first->left && !cur.first->right) res += cur.second;
            else {
                if (cur.first->left) st.push(make_pair(cur.first->left, cur.second*10+cur.first->left->val));
                if (cur.first->right) st.push(make_pair(cur.first->right, cur.second*10+cur.first->right->val));
            }
        }
        return res;
    }
};