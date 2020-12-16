/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pt, qt;
        helper(root, pt, p);
        helper(root, qt, q);
        TreeNode* res = nullptr;
        for (int i=0;i<pt.size() && i<qt.size();++i) {
            if (qt[qt.size()-1-i] == pt[pt.size()-1-i]) res = qt[qt.size()-1-i];
            else break;
        }
        return res;
    }
private:
    bool helper(TreeNode* root, vector<TreeNode*>& t, TreeNode* p) {
        if (!root) return false;
        if (root->val == p->val || helper(root->left, t, p) || helper(root->right, t, p)) {
            t.push_back(root);
            return true;
        }
        return false;
    }
};

// Better: 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : (!right ? left : root);
    }
};