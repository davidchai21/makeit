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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return vector<TreeNode*>();
        vector<TreeNode*> res(1,new TreeNode(1));
        for (int i = 2;i<=n;++i) {
            vector<TreeNode*> t;
            for (TreeNode* root: res) {
                helper(root, i, t);
            }
            swap(t, res);
        }
        return res;
    }
private:
    void helper(TreeNode* root, int k, vector<TreeNode*>& t) {
        TreeNode* leftTree = deepCopy(root);
        TreeNode* baseTree = new TreeNode(k);
        baseTree->left = leftTree;
        t.push_back(baseTree);
        
        TreeNode* cur = root;
        int level = 0;
        while (cur) {
            TreeNode* newTree = deepCopy(root);
            TreeNode* newRoot = newTree;
            for (int i=0;i<level;++i) {
                newRoot = newRoot->right;
            }
            TreeNode* tail = newRoot->right;
            newRoot->right = new TreeNode(k);
            newRoot->right->left = tail;
            t.push_back(newTree);
            cur = cur->right;
            ++level;
        }
    }
    
    TreeNode* deepCopy(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* node = new TreeNode(root->val);
        node->left = deepCopy(root->left);
        node->right = deepCopy(root->right);
        return node;
    }
};

// divide and conquer:

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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return vector<TreeNode*>();
        return helper(1,n);
    }
private:
    vector<TreeNode*> helper(int left, int right) {
        if (left > right) return vector<TreeNode*>(1, NULL);
        vector<TreeNode*> res;
        for (int k=left;k<=right;++k) {
            vector<TreeNode*> leftTree = helper(left, k-1);
            vector<TreeNode*> rightTree = helper(k+1, right);
            for (TreeNode* leftPart: leftTree) {
                for (TreeNode* rightPart: rightTree) {
                    TreeNode* root = new TreeNode(k);
                    root->left = deepCopy(leftPart);
                    root->right = deepCopy(rightPart);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    TreeNode* deepCopy(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = deepCopy(root->left);
        newRoot->right = deepCopy(root->right);
        return newRoot;
    }
};