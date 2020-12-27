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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 = helper(root1);
        vector<int> v2 = helper(root2);
        return compare(v1, v2);
    }
private:
    vector<int> helper(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (!root->left && !root->right) res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
    
    bool compare(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) return false;
        for (int i=0;i<a.size();++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};

// Better:

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        st1.push(root1);
        st2.push(root2);
        while (!st1.empty() && !st2.empty()) {
            if (helper(st1) != helper(st2)) return false;
        }
        return st1.empty() && st2.empty();
    }
private:
    int helper(stack<TreeNode*>& st) {
        while (true) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
            if (!cur->left && !cur->right) return cur->val;
        }
    }
};