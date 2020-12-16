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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> t;
        helper(root, res, t);
        return res;
    }
private:
    void helper(TreeNode* root, vector<string>& res, vector<int>& t) {
        if (!root) return;
        t.push_back(root->val);
        if (!root->left && !root->right) {
            res.push_back(generate(t));
        }
        helper(root->left, res, t);
        helper(root->right, res, t);
        t.pop_back();
    }
    string generate(vector<int>& t) {
        string res = to_string(t[0]);
        for (int i=1;i<t.size();++i) {
            res += "->" + to_string(t[i]);
        }
        return res;
    }
};

// Another:

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        helper(root, res, to_string(root->val));
        return res;
    }
private:
    void helper(TreeNode* root, vector<string>& res, string s) {
        if (!root->left && !root->right) {
            res.push_back(s);
            return;
        }
        if (root->left) helper(root->left, res, s+"->"+to_string(root->left->val));
        if (root->right) helper(root->right, res, s+"->"+to_string(root->right->val));
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        stack<pair<TreeNode*, string>> st;
        st.push(make_pair(root, to_string(root->val)));
        while (!st.empty()) {
            TreeNode* root = st.top().first;
            string s = st.top().second;
            st.pop();
            if (!root->left && !root->right) {
                res.push_back(s);
                continue;
            }
            if (root->left) {
                st.push(make_pair(root->left, s+"->"+to_string(root->left->val)));
            }
            if (root->right) {
                st.push(make_pair(root->right, s+"->"+to_string(root->right->val)));
            }
        }
        return res;
    }
};