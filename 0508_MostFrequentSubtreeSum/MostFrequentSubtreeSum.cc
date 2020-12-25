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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        unordered_map<int, int> m;
        int high = 0;
        helper(root, m, high);
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == high) res.push_back(it->first);
        }
        return res;
    }
private:
    int helper(TreeNode* root, unordered_map<int,int>& m, int& high) {
        if (!root) return 0;
        int left = helper(root->left, m, high);
        int right = helper(root->right, m, high);
        int res = left + right + root->val;
        ++m[res];
        high = max(high, m[res]);
        return res;
    }
};