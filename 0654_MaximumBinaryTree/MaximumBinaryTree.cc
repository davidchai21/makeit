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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int index = left;
        for (int i=left;i<=right;++i) {
            if (nums[i] > nums[index]) index = i;
        }
        TreeNode* root = new TreeNode(nums[index]);
        root->left = helper(nums, left, index-1);
        root->right = helper(nums, index+1, right);
        return root;
    }
};

// Iterative O(n) Solution:

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        for (int i=0;i<nums.size();++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            if (st.empty() || st.top()->val > nums[i]) st.push(cur);
            else {
                pre = nullptr;
                while (!st.empty() && st.top()->val < nums[i]) {
                    st.top()->right = pre;
                    pre = st.top();
                    st.pop();
                }
                cur->left = pre;
                st.push(cur);
            }
        }
        pre = nullptr;
        while (!st.empty()) {
            st.top()->right = pre;
            pre = st.top();
            st.pop();
        }
        return pre;
    }
};