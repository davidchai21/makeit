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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        unordered_map<int, vector<int>> m;
        build(root, m);
        unordered_set<int> seen;
        seen.insert(x);
        int point = 0;
        for (int& neighbor : m[x]) {
            point = max(point, helper(m, seen, neighbor));
        }
        return point*2 > n;
    }
private:
    void build(TreeNode* root, unordered_map<int, vector<int>>& m) {
        if (!root) return;
        if (root->left) {
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
        }
        if (root->right) {
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
        }
        build(root->left, m);
        build(root->right, m);
    }
    
    int helper(unordered_map<int, vector<int>>& m, unordered_set<int> seen, int start) {
        seen.insert(start);
        int res = 0;
        queue<int> q({start});
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++res;
            seen.insert(cur);
            for (int& k: m[cur]) {
                if (seen.find(k) == seen.end()) q.push(k);
            }
        }
        return res;
    }
};

// Better Solution:
// Essence is to find the total nodes in parent/left/right path. Whichever one is greater than n/2, it will win.

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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int left, right;
        helper(root, x, left, right);
        return max(n-left-right-1, max(left, right))*2 > n;
    }
private:
    int helper(TreeNode* root, int x, int& _left, int& _right) {
        if (!root) return 0;
        int left = helper(root->left, x, _left, _right);
        int right = helper(root->right, x, _left, _right);
        if (root->val == x) {
            _left = left;
            _right = right;
        }
        return left+right+1;
    }
};