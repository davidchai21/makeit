/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!K) return {target->val};
        unordered_map<TreeNode*, vector<TreeNode*>> m;
        function<void(TreeNode*)> build = [&](TreeNode* root) {
            if (!root) return;
            if (root->left) {
                m[root].push_back(root->left);
                m[root->left].push_back(root);
            }
            if (root->right) {
                m[root].push_back(root->right);
                m[root->right].push_back(root);
            }
            build(root->left);
            build(root->right);
        };
        build(root);
        
        unordered_set<TreeNode*> seen;
        queue<TreeNode*> q;
        q.push(target);
        seen.insert(target);
        vector<int> res;
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            if (depth == K) {
                for (int i=0;i<size;++i) {
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }
            for (int i=0;i<size;++i) {
                TreeNode* cur = q.front();
                q.pop();
                for (TreeNode*& node: m[cur]) {
                    if (seen.find(node) == seen.end()) {
                        seen.insert(node);
                        q.push(node);
                    }
                }
            }
            ++depth;
        }
        return res;
    }
};