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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        traverse(root, sum, res);
        return res;
    }
private:
    void traverse(TreeNode* root, int sum, int& res) {
        if (!root) return;
        helper(root, sum, res);
        traverse(root->left, sum, res);
        traverse(root->right, sum, res);
    } 
    
    void helper(TreeNode* root, int sum, int& res) {
        if (!root) return;
        if (root->val == sum) ++res;
        helper(root->left, sum-root->val, res);
        helper(root->right, sum-root->val, res);
    }
};

// Using unordered_map:

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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> m;
        int res = 0;
        m[0] = 1;
        helper(root, sum, m, 0, res);
        return res;
    }
private:
    void helper(TreeNode* root, int sum, unordered_map<int,int>& m, int cur, int& res) {
        if (!root) return;
        cur += root->val;
        if (m.find(cur-sum) != m.end()) res += m[cur-sum];
        ++m[cur];
        helper(root->left, sum, m, cur, res);
        helper(root->right, sum, m, cur, res);
        --m[cur];
    }
};