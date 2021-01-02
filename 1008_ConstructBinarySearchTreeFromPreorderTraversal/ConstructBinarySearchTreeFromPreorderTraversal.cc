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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        stack<TreeNode*> st;
        TreeNode* root = nullptr;
        TreeNode* res = nullptr;
        for (int& p: preorder) {
            TreeNode* node = new TreeNode(p);
            if (!res) res = node;
            if (!st.empty() && st.top()->val > p) {
                st.top()->left = node;
            } else {
                while (!st.empty() && st.top()->val < p) {
                    root = st.top();
                    st.pop();
                }
                if (root) root->right = node;
            }
            st.push(node);
        }
        return res;
    }
};

// Recursive:

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>::iterator begin = preorder.begin();
        vector<int>::iterator end = preorder.end();
        return helper(begin, end);
    }
private:
    TreeNode* helper(vector<int>::iterator begin, vector<int>::iterator& end) {
        if (begin == end) return nullptr;
        TreeNode* root = new TreeNode(*begin);
        
        auto right = upper_bound(begin+1, end, *begin);
        root->left = helper(begin+1, right);
        root->right = helper(right, end);
        
        return root;
    }
};