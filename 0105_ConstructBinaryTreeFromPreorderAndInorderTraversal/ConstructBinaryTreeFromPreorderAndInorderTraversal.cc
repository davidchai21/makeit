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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* helper(vector<int>& pre, int pi, int pj, vector<int>& in, int ii, int ij) {
        if (pi>pj) return nullptr;
        TreeNode* root = new TreeNode(pre[pi]);
        int pos = find(in.begin()+ii, in.begin()+ij+1, pre[pi])-in.begin()-ii;
        root->left = helper(pre, pi+1, pi+pos, in, ii, ii+pos-1);
        root->right = helper(pre, pi+pos+1, pj, in, ii+pos+1, ij);
        return root;
    }
};