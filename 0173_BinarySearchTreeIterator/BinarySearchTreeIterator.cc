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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
        TreeNode* cur = st.top();
        st.pop();
        int res = cur->val;
        cur = cur->right;
        helper(cur);
        return res;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    stack<TreeNode*> st;
    void helper(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */