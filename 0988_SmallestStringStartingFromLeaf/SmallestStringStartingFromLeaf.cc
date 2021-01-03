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
    string smallestFromLeaf(TreeNode* root) {
        string t = "";
        vector<string> res;
        helper(root, t, res);
        for (string& s: res) reverse(s.begin(), s.end());
        string result = res.front();
        for (string& s: res) {
            if (result.compare(s) > 0) result = s;
        }
        return result;
    }
private:
    void helper(TreeNode* root, string& t, vector<string>& res) {
        if (!root) return;
        t.push_back('a'+root->val);
        if (!root->left && !root->right) {
            res.push_back(t);
        } else {
            helper(root->left, t, res);
            helper(root->right, t, res);
        }
        t.pop_back();
    }
};

// Better:

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
    string smallestFromLeaf(TreeNode* root) {
        string res = "~";
        helper(root, res, "");
        return res;
    }
private:
    void helper(TreeNode* root, string& res, string t) {
        if (!root) return;
        if (!root->left && !root->right) {
            res = min(res, char('a'+root->val)+t);
            return;
        }
        helper(root->left, res, char('a'+root->val)+t);
        helper(root->right, res, char('a'+root->val)+t);
    }
};