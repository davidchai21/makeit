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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size() || inorder.empty()) return nullptr;
        reverse(inorder.begin(), inorder.end());
        reverse(postorder.begin(), postorder.end());
        int n = inorder.size();
        return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ii, int ij, int pi, int pj) {
        if (ii> ij) return nullptr;
        TreeNode* root = new TreeNode(postorder[pi]);
        int pos = find(inorder.begin()+ii, inorder.begin()+ij+1, postorder[pi])-inorder.begin()-ii;
        root->right = helper(inorder, postorder, ii, ii+pos-1, pi+1, pi+pos);
        root->left = helper(inorder, postorder, ii+pos+1, ij, pi+pos+1, pj);
        return root;
    }
};