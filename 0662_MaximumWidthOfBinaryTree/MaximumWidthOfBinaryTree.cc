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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long res = 0;
        queue<pair<TreeNode*, long>> q;
        q.push(make_pair(root, 0L));
        while (!q.empty()) {
            int size = q.size();
            long left = 0;
            long right = 0;
            long base = 0;
            for (int i=0;i<size;++i) {
                pair<TreeNode*, long> cur = q.front();
                q.pop();
                if (i == 0) {
                    left = cur.second;
                    base = left;
                }
                if (i == size-1) right = cur.second;
                if (cur.first->left) q.push(make_pair(cur.first->left, (cur.second-base)*2));
                if (cur.first->right) q.push(make_pair(cur.first->right, (cur.second-base)*2+1));
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};