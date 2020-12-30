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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> table(10,0);
        int res = 0;
        helper(root, res, table);
        return res;
    }
private:
    void helper(TreeNode* root, int& res, vector<int>& table) {
        if (!root) return;
        ++table[root->val];
        if (!root->left && !root->right && check(table)) ++res;
        helper(root->left, res, table);
        helper(root->right, res, table);
        --table[root->val];
    }
    
    bool check(vector<int>& table) {
        int single = 0;
        for (int i=0;i<10;++i) {
            if (table[i]%2) ++single;
        }
        return single < 2;
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
    int pseudoPalindromicPaths (TreeNode* root) {
        int record = 0;
        int res = 0;
        helper(root, res, record);
        return res;
    }
private:
    void helper(TreeNode* root, int& res, int& record) {
        if (!root) return;
        record ^= 1<<(root->val);
        if (!root->left && !root->right && check(record)) ++res;
        helper(root->left, res, record);
        helper(root->right, res, record);
        record ^= 1<<root->val;
    }
    
    bool check(int& record) {
        return (record & (record-1)) == 0;
    }
};