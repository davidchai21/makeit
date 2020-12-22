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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        collect(root, nodes);
        return generate(nodes, 0, nodes.size()-1);
    }
private:
    void collect(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        collect(root->left, nodes);
        nodes.push_back(root);
        collect(root->right, nodes);
    }
    
    TreeNode* generate(vector<TreeNode*>& nodes, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left)/2;
        TreeNode* root = nodes[mid];
        root->left = generate(nodes, left, mid-1);
        root->right = generate(nodes, mid+1, right);
        return root;
    }
};