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
        if (!root) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return helper(ss);
    }
private:
    TreeNode* helper(istringstream& ss) {
        string word;
        ss >> word;
        if (word == "#") {
            return nullptr;
        } else {
            TreeNode* root = new TreeNode(stoi(word));
            root->left = helper(ss);
            root->right = helper(ss);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));