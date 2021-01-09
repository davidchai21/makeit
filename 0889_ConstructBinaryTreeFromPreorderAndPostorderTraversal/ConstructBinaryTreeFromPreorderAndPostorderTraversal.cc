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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, post, 0, pre.size()-1, 0, post.size()-1);
    }
private:
    TreeNode* helper(vector<int>& pre, vector<int>& post, int a, int b, int c, int d) {
        if (a > b) return nullptr;
        if (a == b) return new TreeNode(pre[a]);
        int i = c;
        for (;i<d;++i) {
            if (post[i] == pre[a+1]) break;
        }
        TreeNode* root = new TreeNode(pre[a]);
        root->left = helper(pre, post, a+1, i+1-c+a, c, i);
        root->right = helper(pre, post, i+2-c+a, b, i+1, d-1);
        return root;
    }
};