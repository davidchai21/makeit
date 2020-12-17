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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* res = new TreeNode(v);
            res->left = root;
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        --d;
        while (--d) {
            int size = q.size();
            for (int i=0;i<size;++i) {
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            TreeNode* left = cur->left;
            cur->left = new TreeNode(v);
            cur->left->left = left;
            TreeNode* right = cur->right;
            cur->right = new TreeNode(v);
            cur->right->right = right;
        }
        return root;
    }
};

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return helper(root, v, d, true);
    }
private:
    TreeNode* helper(TreeNode* root, int v, int d, bool isLeft) {
        if (!root) return d==1?(new TreeNode(v)):nullptr;
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            if (isLeft) node->left = root;
            else node->right = root;
            return node;
        }
        root->left = helper(root->left, v, d-1, true);
        root->right = helper(root->right, v, d-1, false);
        return root;
    }
};