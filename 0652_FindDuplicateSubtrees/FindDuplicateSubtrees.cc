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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        unordered_map<string, TreeNode*> record;
        helper(root, m, record);
        vector<TreeNode*> res;
        for (auto it = m.begin();it!=m.end();++it) {
            if (it->second > 1) {
                res.push_back(record[it->first]);
            }
        }
        return res;
    }
private:
    string helper(TreeNode* root, unordered_map<string, int>& m, unordered_map<string, TreeNode*>& record) {
        if (!root) return "";
        string left = helper(root->left, m, record);
        string right = helper(root->right, m, record);
        string res = to_string(root->val) + "," + left + "," + right;
        ++m[res];
        record[res] = root;
        return res;
    }
};