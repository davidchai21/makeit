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

struct Node {
    int min;
    int max;
    bool notNull;
    Node(bool _notNull): notNull(_notNull), min(0), max(0) {};
    Node(int _min, int _max, bool _notNull): notNull(_notNull), min(_min), max(_max) {};
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    Node* helper(TreeNode* root, int& res) {
        if (!root) return new Node(false);
        Node* left = helper(root->left, res);
        Node* right = helper(root->right, res);
        if (!left->notNull && !right->notNull) {
            return new Node(root->val, root->val, true);
        }
        int cur_min = min(left->notNull?left->min:INT_MAX, right->notNull?right->min:INT_MAX);
        int cur_max = max(left->notNull?left->max:INT_MIN, right->notNull?right->max:INT_MIN);
        res = max(res, max(abs(root->val-cur_min), abs(root->val-cur_max)));
        return new Node(min(cur_min, root->val), max(cur_max, root->val), true);
    }
};

// Top-down:

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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        helper(root, root->val, root->val, res);
        return res;
    }
private:
    void helper(TreeNode* root, int curmax, int curmin, int& res) {
        if (!root) {
            res = max(res, curmax-curmin);
            return;
        }
        curmax = max(root->val, curmax);
        curmin = min(root->val, curmin);
        helper(root->left, curmax, curmin, res);
        helper(root->right, curmax, curmin, res);
    }
};

// Another top-down:

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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        helper(root, root->val, root->val, res);
        return res;
    }
private:
    void helper(TreeNode* root, int curmin, int curmax, int& res) {
        if (!root) return;
        curmax = max(curmax, root->val);
        curmin = min(curmin, root->val);
        int newRes = curmax - curmin;
        res = max(res, newRes);
        helper(root->left, curmin, curmax, res);
        helper(root->right, curmin, curmax, res);
    }
};