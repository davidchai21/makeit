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
struct Record {
    int min;
    int max;
    int count;
    Record(int min, int max, int count):min(min), max(max), count(count) {};
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
private:
    Record* helper(TreeNode* root, int& res) {
        if (!root) return new Record(0,0,0);
        Record* left = helper(root->left, res);
        Record* right = helper(root->right, res);
        if (left->count<0 || right->count<0) return new Record(0,0,-1);
        if ((!left->count || left->max < root->val) && (!right->count || right->min > root->val)) {
            int count = left->count+right->count+1;
            res = max(res, count);
            int cur_min = left->count ? left->min : root->val;
            int cur_max = right->count ? right->max : root->val;
            return new Record(cur_min, cur_max, count);
        }
        return new Record(0,0,-1);
    }
};