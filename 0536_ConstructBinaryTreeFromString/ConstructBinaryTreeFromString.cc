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
    TreeNode* str2tree(string s) {
        stack<TreeNode*> st;
        int val = 0;
        int mark = 1;
        for (int i=0;i<s.size();++i) {
            if (s[i] == '-') mark = -mark;
            else if (isdigit(s[i])) val = val*10+s[i]-'0';
            else if (s[i]=='(') {
                if (s[i-1]!=')') {
                    TreeNode* node = new TreeNode(val*mark);
                    val = 0;
                    mark = 1;
                    if (!st.empty()) {
                        if (!st.top()->left) st.top()->left = node;
                        else st.top()->right = node;
                    }
                    st.push(node);
                }
            }
            else {
                if (s[i-1]==')') {
                    st.pop();
                } else {
                    TreeNode* node = new TreeNode(val*mark);
                    val = 0;
                    mark = 1;
                    if (st.top()->left) st.top()->right = node;
                    else st.top()->left = node;
                }
            }
        }
        if (st.empty() && !s.empty()) return new TreeNode(val*mark);
        return st.empty() ? nullptr : st.top();
    }
};

// DFS:

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
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        int index = 0;
        return helper(s, index);
    }
private:
    TreeNode* helper(string& s, int& index) {
        if (index >= s.size()) return nullptr;
        
        int sign = 1;
        int val = 0;
        if (s[index] == '-') {
            sign = -1;
            ++index;
        }
        while (index < s.size() && isdigit(s[index])) {
            val = val*10+(s[index++]-'0');
        }
        
        TreeNode* root = new TreeNode(sign*val);
        if (index < s.size() && s[index] == '(') {
            ++index;
            root->left = helper(s, index);
            ++index;
            
            if (index<s.size() && s[index] == '(') {
                ++index;
                root->right = helper(s, index);
                ++index;
            }
        }
        
        return root;
    }
};