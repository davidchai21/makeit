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
    TreeNode* recoverFromPreorder(string S) {
        TreeNode* dummy = new TreeNode();
        TreeNode* cur = dummy;
        int val = 0;
        for (int i=0;i<S.size();++i) {
            if (isdigit(S[i])) val = val*10+S[i]-'0';
            else {
                if (isdigit(S[i-1])) {
                    TreeNode* node = new TreeNode(val);
                    val = 0;
                    if (cur->left) {
                        cur->right = node;
                    } else {
                        cur->left = node;
                    }
                    cur = dummy->left;
                } else {
                    if (cur->right) cur = cur->right;
                    else cur = cur->left;
                }
            }
        }
        if (cur->left) cur->right = new TreeNode(val);
        else cur->left = new TreeNode(val);
        return dummy->left;
    }
};

// Iterative:

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
    TreeNode* recoverFromPreorder(string S) {
        S.append("-");
        vector<TreeNode*> st;
        int val = 0;
        int level = 0;
        for (int i=0;i<S.size();++i) {
            if (isdigit(S[i])) val = val*10+S[i]-'0';
            else {
                if (isdigit(S[i-1])) {
                    while (level < st.size()) st.pop_back();
                    TreeNode* node = new TreeNode(val);
                    val = 0;
                    level = 0;
                    if (!st.empty()) {
                        if (st.back()->left) st.back()->right = node;
                        else st.back()->left = node;
                    }
                    st.push_back(node);
                }
                ++level;
            }
        }
        return st.front();
    }
};