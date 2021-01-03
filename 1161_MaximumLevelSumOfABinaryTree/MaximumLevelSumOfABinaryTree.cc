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
    int maxLevelSum(TreeNode* root) {
        int res = 1;
        int sum = root->val;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int _sum = 0;
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                _sum += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (_sum > sum) {
                sum = _sum;
                res = level;
            }
            ++level;
        }
        return res;
    }
};

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
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        int res = 1;
        int maxSum = root->val;
        helper(root, sum, 1);
        for (int i = 0;i<sum.size();++i) {
            if (maxSum < sum[i]) {
                maxSum = sum[i];
                res = i+1;
            }
        }
        return res;
    }
private:
    void helper(TreeNode* root, vector<int>& sum, int level) {
        if (!root) return;
        if (level > sum.size()) sum.push_back(0);
        sum[level-1] += root->val;
        helper(root->left, sum, level+1);
        helper(root->right, sum, level+1);
    }
};