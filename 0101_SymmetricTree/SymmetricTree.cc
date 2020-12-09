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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || q->val != p->val) return false;
        return helper(p->left, q->right) && helper(p->right, q->left);
    }
};

// Iterative:

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q,p;
        if (root->left) p.push(root->left);
        if (root->right) q.push(root->right);
        while (!q.empty() && !p.empty()) {
            TreeNode* qh = q.front();
            q.pop();
            TreeNode* ph = p.front();
            p.pop();
            if (!helper(ph, qh) || ph->left && !qh->right || !ph->left && qh->right || ph->right && !qh->left || !ph->right && qh->left) return false;
            if (ph->left) {
                p.push(ph->left);
                q.push(qh->right);
            }
            if (ph->right) {
                p.push(ph->right);
                q.push(qh->left);
            }
        }
        return p.empty() && q.empty();
    }
private:
    bool helper(TreeNode* q, TreeNode* p) {
        if (!p && !q) return true;
        if (!q || !p || p->val != q->val) return false;
        return true;
    }
};

// Another iterative:

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q,p;
        p.push(root->left);
        q.push(root->right);
        while (!p.empty()) {
            TreeNode* left = p.front();
            p.pop();
            TreeNode* right = q.front();
            q.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            p.push(left->left);
            p.push(left->right);
            q.push(right->right);
            q.push(right->left);
        }
        return true;
    }
};