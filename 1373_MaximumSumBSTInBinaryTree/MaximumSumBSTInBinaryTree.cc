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
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    struct all {
        int sum;
        int min;
        int max;
        bool isBST;
        all(int sum, int min, int max, bool isBST):sum(sum),min(min),max(max),isBST(isBST) {};
    };
    
    all* helper(TreeNode* root, int& res) {
        if (!root) return nullptr;
        all* left = helper(root->left, res);
        all* right = helper(root->right, res);
        if ((!left || left->isBST && left->max < root->val) && (!right || right->isBST && right->min > root->val)) {
            int sum = (left?left->sum:0) + root->val + (right?right->sum:0);
            res = max(res, sum);
            int all_min = left?left->min:root->val;
            int all_max = right?right->max:root->val;
            return new all(sum, all_min, all_max, true);
        }
        return new all(0,0,0,false);
    }
};