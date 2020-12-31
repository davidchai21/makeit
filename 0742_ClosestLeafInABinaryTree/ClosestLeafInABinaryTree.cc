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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> m;
        TreeNode* start = nullptr;
        function<void(TreeNode*, int)> build = [&](TreeNode* root, int k) {
            if (!root) return;
            if (root->val == k) start = root;
            if (root->left) {
                m[root].push_back(root->left);
                m[root->left].push_back(root);
            }
            if (root->right) {
                m[root].push_back(root->right);
                m[root->right].push_back(root);
            }
            build(root->left, k);
            build(root->right, k);
        };
        build(root, k);
        
        unordered_set<TreeNode*> seen;
        queue<TreeNode*> q;
        q.push(start);
        seen.insert(start);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur->left && !cur->right) return cur->val;
            for (TreeNode*& t:m[cur]) {
                if (seen.find(t) == seen.end()) {
                    seen.insert(t);
                    q.push(t);
                }
            }
        }
        return -1;
    }
};