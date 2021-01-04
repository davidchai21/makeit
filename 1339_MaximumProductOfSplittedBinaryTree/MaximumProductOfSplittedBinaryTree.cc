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
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        int base = getSum(root, m);
        long res = 0;
        for (auto it = m.begin();it!=m.end();++it) {
            res = max(res, (long)it->second*(base-it->second));
        }
        return res%mod;
    }
private:
    const int mod = 1000000007;
    int getSum(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (!root) return 0;
        int left = getSum(root->left, m);
        int right = getSum(root->right, m);
        m[root] = left + right + root->val;
        return m[root];
    }
};

// Save space:

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
    int maxProduct(TreeNode* root) {
        long res = 0;
        int base = getSum(root);
        findRes(root, base, res);
        return res%mod;
    }
private:
    const int mod = 1000000007;
    
    int getSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    
    int findRes(TreeNode* root, int& base, long& res) {
        if (!root) return 0;
        long sum = root->val + findRes(root->left, base, res) + findRes(root->right, base, res);
        res = max(res, sum*(base-sum));
        return sum;
    }
};