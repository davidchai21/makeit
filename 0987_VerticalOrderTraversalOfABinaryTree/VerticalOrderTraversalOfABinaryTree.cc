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

struct Info {
    int row;
    int offset;
    int val;
    Info(int _row, int _offset, int _val):val(_val), row(_row), offset(_offset) {};
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Info*> record;
        helper(root, record, 0, 0);
        sort(record.begin(), record.end(), [](Info*& a, Info*& b){
            return a->offset < b->offset || a->offset == b->offset && a->row < b->row || a->offset == b->offset && a->row == b->row && a->val < b->val;
        });
        vector<vector<int>> res;
        int offset = 1;
        for (Info*& info: record) {
            if (info->offset != offset) {
                offset = info->offset;
                res.push_back({info->val});
            } else {
                res.back().push_back(info->val);
            }
        }
        return res;
    }
private:
    void helper(TreeNode* root, vector<Info*>& record, int row, int level) {
        if (!root) return;
        Info* node = new Info(row, level, root->val);
        record.push_back(node);
        helper(root->left, record, row+1, level-1);
        helper(root->right, record, row+1, level+1);
    }
};