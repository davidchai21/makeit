// DFS:

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
    bool isCousins(TreeNode* root, int x, int y) {
        int lx = -1, ly = -1;
        TreeNode* px = nullptr;
        TreeNode* py = nullptr;
        findParent(root, 0, lx, px, nullptr, x);
        findParent(root, 0, ly, py, nullptr, y);
        return lx == ly && px != py;
    }
private:
    void findParent(TreeNode* root, int l, int& level, TreeNode*& parent, TreeNode* pre, int val) {
        if (!root || parent) return;
        if (root->val == val) {
            parent = pre;
            level = l;
            return;
        }
        findParent(root->left, l+1, level, parent, root, val);
        findParent(root->right, l+1, level, parent, root, val);
    }
};

// BFS:

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = 0;
            TreeNode* px = nullptr;
            TreeNode* py = nullptr;
            int size = q.size();
            for (int i=0;i<size;++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    if (cur->left->val == x) {
                        px = cur;
                        ++count;
                    }
                    if (cur->left->val == y) {
                        py = cur;
                        ++count;
                    }
                    q.push(cur->left);
                }
                if (cur->right) {
                    if (cur->right->val == x) {
                        px = cur;
                        ++count;
                    }
                    if (cur->right->val == y) {
                        py = cur;
                        ++count;
                    }
                    q.push(cur->right);
                }
            }
            if (count == 1) return false;
            if (count == 2) return px != py;
        }
        return false;
    }
};