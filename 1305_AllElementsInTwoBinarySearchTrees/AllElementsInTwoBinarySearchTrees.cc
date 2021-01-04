// Sort:

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        helper(root1, res);
        helper(root2, res);
        sort(res.begin(), res.end());
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> st1, st2;
        pushLeft(root1, st1);
        pushLeft(root2, st2);
        while (!st1.empty() || !st2.empty()) {
            stack<TreeNode*>& st = st1.empty() ? st2 : st2.empty() ? st1 : st1.top()->val > st2.top()->val ? st2 : st1;
            TreeNode* root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
            pushLeft(root, st);
        }
        return res;
    }
private:
    void pushLeft(TreeNode* root, stack<TreeNode*>& st) {
        while (root) {
            st.push(exchange(root, root->left));
        }
    }
};