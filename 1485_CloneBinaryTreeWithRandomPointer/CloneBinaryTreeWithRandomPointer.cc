/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> m;
        NodeCopy* res = generate(root, m);
        update(root, m);
        return res;
    }
private:
    NodeCopy* generate(Node* root, unordered_map<Node*, NodeCopy*>& m) {
        if (!root) return nullptr;
        NodeCopy* node = new NodeCopy(root->val);
        m[root] = node;
        node->left = generate(root->left, m);
        node->right = generate(root->right, m);
        return node;
    }
    
    void update(Node* root, unordered_map<Node*, NodeCopy*>& m) {
        if (!root) return;
        if (root->random) {
            m[root]->random = m[root->random];
        }
        update(root->left, m);
        update(root->right, m);
    }
};

// One time traversal:

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> m;
        return helper(root, m);
    }
private:
    NodeCopy* helper(Node* root, unordered_map<Node*, NodeCopy*>& m) {
        if (!root) return nullptr;
        if (m.find(root) != m.end()) return m[root];
        
        NodeCopy* node = new NodeCopy(root->val);
        m[root] = node;
        
        node->left = helper(root->left, m);
        node->right = helper(root->right, m);
        node->random = helper(root->random, m);
        
        return node;
    } 
};