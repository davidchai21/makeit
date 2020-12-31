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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        _root = root;
        q.push(root);
        while (true) {
            TreeNode* cur = q.front();
            if (!cur->left || !cur->right) break;
            q.push(cur->left);
            q.push(cur->right);
            q.pop();
        }
    }
    
    int insert(int v) {
        TreeNode* cur = q.front();
        if (!cur->left) {
            cur->left = new TreeNode(v);
        } else {
            cur->right = new TreeNode(v);
            q.pop();
            q.push(cur->left);
            q.push(cur->right);
        }
        return cur->val;
    }
    
    TreeNode* get_root() {
        return _root;
    }
private:
    queue<TreeNode*> q;
    TreeNode* _root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */