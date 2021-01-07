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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N%2==0) return res;
        unordered_map<int, vector<TreeNode*>> m;
        m[1].push_back(new TreeNode(0));
        return helper(N, m);
    }
private:
    vector<TreeNode*> helper(int n, unordered_map<int, vector<TreeNode*>>& m) {
        if (m.find(n) != m.end()) return m[n];
        for (int i=1;i<n;i+=2) {
            int j = n-1-i;
            for (TreeNode* left : helper(i, m)) {
                for (TreeNode* right : helper(j, m)) {
                    TreeNode* root = new TreeNode();
                    root->left = left;
                    root->right = right;
                    m[n].push_back(root);
                }
            }
        }
        return m[n];
    }
};