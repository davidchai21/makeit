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
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        helper(root, distance, res);
        return res;
    }
private:
    vector<int> helper(TreeNode* root, int distance, int& ans) {
        if (!root) return {};
        if (!root->left && !root->right) return {1};
        vector<int> left = helper(root->left, distance, ans);
        vector<int> right = helper(root->right, distance, ans);
        for (int i=0;i<left.size();++i) {
            for (int j=0;j<right.size();++j) {
                if (left[i] + right[j] <= distance) ++ ans;
            }
        }
        vector<int> res;
        for (int i=0;i<left.size();++i) {
            if (left[i]+1 < distance) res.push_back(left[i]+1);
        }
        for (int j=0;j<right.size();++j) {
            if (right[j]+1 < distance) res.push_back(right[j]+1);
        }
        return res;
    }
};