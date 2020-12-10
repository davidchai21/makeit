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
    
    bool hasNext() {
        return !st.empty() || index<record.size();
    }
    
    int next() {
        if (index >= record.size()) {
            TreeNode* cur = st.top();
            st.pop();
            helper(cur->right);
            record.push_back(cur->val);
            ++index;
            return cur->val;
        }
        return record[index++];
    }
    
    bool hasPrev() {
        return index>1;
    }
    
    int prev() {
        return record[--index-1];
    }
private:
    int index = 0;
    vector<int> record;
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
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */