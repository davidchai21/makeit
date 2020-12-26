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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = findHeight(root);
        vector<vector<string>> res(h, vector<string>(pow(2,h)-1, ""));
        if (!h) return res;
        process(root, res, pow(2,h-1)-1, 0, h);
        return res;
    }
private:
    int findHeight(TreeNode* root) {
        if (!root) return 0;
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        return max(left, right) + 1;
    }
    
    void process(TreeNode* root, vector<vector<string>>& res, int pos, int depth, int h) {
        if (!root) return;
        res[depth][pos] = to_string(root->val);
        int diff = pow(2,h-depth-2);
        process(root->left, res, pos-diff, depth+1, h);
        process(root->right, res, pos+diff, depth+1, h);
    }
};

// Iterative:

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

struct Info {
    TreeNode* root;
    int pos;
    int diff;
    
    Info(TreeNode* root, int pos, int diff):root(root), pos(pos), diff(diff) {};
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<string>> res(height, vector<string>(pow(2, height)-1, ""));
        queue<Info*> q;
        q.push(new Info(root, pow(2, height-1)-1, pow(2, height-1)));
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;++i) {
                Info* cur = q.front();
                q.pop();
                res[depth][cur->pos] = to_string(cur->root->val);
                if (cur->root->left) q.push(new Info(cur->root->left, cur->pos-cur->diff/2, cur->diff/2));
                if (cur->root->right) q.push(new Info(cur->root->right, cur->pos+cur->diff/2, cur->diff/2));
            }
            ++depth;
        }
        return res;
    }
private:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
};