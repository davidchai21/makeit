// DFS:

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> o, n;
        while (original || !o.empty()) {
            while (original) {
                o.push(original);
                n.push(cloned);
                original = original->left;
                cloned = cloned->left;
            }
            original = o.top();
            o.pop();
            cloned = n.top();
            n.pop();
            if (target == original) return cloned;
            original = original->right;
            cloned = cloned->right;
        }
        return nullptr;
    }
};

// BFS:

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> o,n;
        o.push(original);
        n.push(cloned);
        while (!o.empty()) {
            TreeNode* curo = o.front();
            o.pop();
            TreeNode* curn = n.front();
            n.pop();
            if (curo == target) return curn;
            if (curo->left) {
                o.push(curo->left);
                n.push(curn->left);
            }
            if (curo->right) {
                o.push(curo->right);
                n.push(curn->right);
            }
        }
        return nullptr;
    }
};