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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        unordered_map<int, vector<int>> m;
        int minLevel = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* cur = q.front().first;
                int level = q.front().second;
                q.pop();
                m[level].push_back(cur->val);
                if (cur->left) {
                    q.push(make_pair(cur->left, level-1));
                    minLevel = min(minLevel, level-1);
                }
                if (cur->right) q.push(make_pair(cur->right, level+1));
            }
        }
        
        res.resize(m.size());
        for (int i=0;i<m.size();++i) {
            res[i] = m[i+minLevel];
        }
        return res;
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        unordered_map<int, vector<pair<int,int>>> m;
        int minLevel = 0;
        helper(root, 0, 0, m, minLevel);
        res.resize(m.size());
        for (int i=0;i<m.size();++i) {
            int index = i+minLevel;
            sort(m[index].begin(), m[index].end(), [](pair<int,int>& a, pair<int,int>& b){
                return a.first < b.first;
            });
            res[i].resize(m[index].size());
            for (int j=0;j<res[i].size();++j) {
                res[i][j] = m[index][j].second;
            }
        }
        return res;
    }
private:
    struct Node {
        int x, y, val;
        Node(int _x, int _y, int _val):x(_x), y(_y), val(_val) {};
    };
    
    void helper(TreeNode* root, int row, int col, unordered_map<int, vector<pair<int,int>>>& m, int& minLevel) {
        if (!root) return;
        minLevel = min(minLevel, col);
        m[col].push_back(make_pair(row, root->val));
        helper(root->left, row+1, col-1, m, minLevel);
        helper(root->right, row+1, col+1, m, minLevel);
    }
};