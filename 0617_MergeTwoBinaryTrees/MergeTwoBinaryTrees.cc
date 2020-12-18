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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        TreeNode* root = new TreeNode((t1?t1->val:0) + (t2?t2->val:0));
        root->left = mergeTrees(t1?t1->left:nullptr, t2?t2->left:nullptr);
        root->right = mergeTrees(t1?t1->right:nullptr, t2?t2->right:nullptr);
        return root;
    }
};

// Another:

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) return t1 ? t1 : t2;
        stack<TreeNode*> s1,s2,s;
        s1.push(t1);
        s2.push(t2);
        s.push(new TreeNode(t1->val + t2->val));
        TreeNode* res = s.top();
        while (!s1.empty()) {
            TreeNode* cur1 = s1.top();
            TreeNode* cur2 = s2.top();
            TreeNode* cur = s.top();
            s1.pop();
            s2.pop();
            s.pop();
            if (cur1 && cur1->left || cur2 && cur2->left) {
                TreeNode* left = new TreeNode((cur1 && cur1->left?cur1->left->val:0) + (cur2&&cur2->left?cur2->left->val:0));
                cur->left = left;
                s1.push(cur1?cur1->left:nullptr);
                s2.push(cur2?cur2->left:nullptr);
                s.push(left);
            }
            if (cur1 && cur1->right || cur2 && cur2->right) {
                TreeNode* right = new TreeNode((cur1&&cur1->right?cur1->right->val:0) + (cur2&&cur2->right?cur2->right->val:0));
                cur->right = right;
                s1.push(cur1?cur1->right:nullptr);
                s2.push(cur2?cur2->right:nullptr);
                s.push(right);
            }
        }
        return res;
    }
};