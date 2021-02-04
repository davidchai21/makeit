/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        vector<int> record(256, 0);
        add(root1, record);
        sub(root2, record);
        for (int i=0;i<256;++i) {
            if (record[i]) return false;
        }
        return true;
    }
private:
    void add(Node* root, vector<int>& record) {
        if (!root) return;
        if (!root->left && !root->right) {
            ++record[root->val];
            return;
        }
        add(root->left, record);
        add(root->right, record);
    }
    
    void sub(Node* root, vector<int>& record) {
        if (!root) return;
        if (!root->left && !root->right) {
            --record[root->val];
            return;
        }
        sub(root->left, record);
        sub(root->right, record);
    }
};