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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        helper(root, m, 1, nullptr);
        return root;
    }
private:
    void helper(TreeNode* root, unordered_map<TreeNode*, int>& m, int level, TreeNode* parent) {
        if (!root) return;
        if (root->right && m.find(root->right) != m.end() && m[root->right] == level) {
            root->right = nullptr;
            if (parent->left == root) parent->left = nullptr;
            else parent->right = nullptr;
            return;
        }
        m[root] = level;
        helper(root->right, m, level+1, root);
        helper(root->left, m, level+1, root);
    }
};

// Using unordered_set:

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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> s;
        return helper(root, s);
    }
private:
    TreeNode* helper(TreeNode* root, unordered_set<TreeNode*>& s) {
        if (!root) return nullptr;
        if (root->right && s.find(root->right) != s.end()) return nullptr;
        s.insert(root);
        root->right = helper(root->right, s);
        root->left = helper(root->left, s);
        return root;
    }
};