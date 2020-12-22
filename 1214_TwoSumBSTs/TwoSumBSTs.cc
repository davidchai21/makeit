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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s;
        add(root2, s, target);
        return check(root1, s);
    }
private:
    void add(TreeNode* root, unordered_set<int>& s, int target) {
        if (!root) return;
        s.insert(target - root->val);
        add(root->left, s, target);
        add(root->right, s, target);
    }
    
    bool check(TreeNode* root, unordered_set<int>& s) {
        if (!root) return false;
        if (s.find(root->val) != s.end()) return true;
        return check(root->left, s) || check(root->right, s);
    }
};

// Two Stack Solution:

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (!root1 || !root2) return false;
        stack<TreeNode*> s1, s2;
        while ((root1 || !s1.empty()) && (root2 || !s2.empty())) {
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }
            while (root2) {
                s2.push(root2);
                root2 = root2->right;
            }
            int sum = s1.top()->val + s2.top()->val;
            if (sum == target) return true;
            else if (sum > target) {
                root2 = s2.top()->left;
                s2.pop();
            } else {
                root1 = s1.top()->right;
                s1.pop();
            }
        }
        return false;
    }
};