/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                res.append(to_string(root->val)+",");
                root = root->left;
            } else {
                root = st.top()->right;
                st.pop();
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        int val = 0;
        TreeNode* res, *cur;
        stack<TreeNode*> st;
        for (int i=0;i<data.size();++i) {
            if (data[i] != ',') val = val*10 + data[i] - '0';
            else {
                TreeNode* node = new TreeNode(val);
                if (st.empty()) {
                    res = node;
                } else if (val < st.top()->val) {
                    st.top()->left = node;
                } else {
                    while (!st.empty() && st.top()->val < val) {
                        cur = st.top();
                        st.pop();
                    }
                    cur->right = node;
                }
                st.push(node);
                val = 0;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;