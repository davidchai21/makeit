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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<int> st;
        queue<int> q;
        helper(root, st, q, target);
        vector<int> res(k);
        int index = 0;
        while (!st.empty() && !q.empty() && index<k) {
            if (target-st.top() < q.front()-target) {
                res[index++] = st.top();
                st.pop();
            } else {
                res[index++] = q.front();
                q.pop();
            }
        }
        while (!st.empty() && index<k) {
            res[index++] = st.top();
            st.pop();
        }
        while (!q.empty() && index<k) {
            res[index++] = q.front();
            q.pop();
        }
        return res;
    }
private:
    void helper(TreeNode* root, stack<int>& st, queue<int>& q, double& target) {
        if (!root) return;
        helper(root->left, st, q, target);
        if (root->val <= target) st.push(root->val);
        else q.push(root->val);
        helper(root->right, st, q, target);
    }
};