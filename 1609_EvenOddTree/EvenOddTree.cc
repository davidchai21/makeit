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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool flag = true;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int std = 0;
            for (int i=0;i<size;++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->val%2 != flag) return false;
                if (i==0) std = cur->val;
                else if (!check(std, cur->val, flag)) return false;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            flag = !flag;
        }
        return true;
    }
private:
    bool check(int& std, int& cur, bool& flag) {
        if (flag) {
            if (std >= cur) return false;
            std = cur;
        } else {
            if (std <= cur) return false;
            std = cur;
        }
        return true;
    }
};