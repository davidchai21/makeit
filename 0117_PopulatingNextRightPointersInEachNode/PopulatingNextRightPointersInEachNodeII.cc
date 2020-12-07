// Intuitive:

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;++i) {
                Node* cur = q.front();
                q.pop();
                if (i<size-1) cur->next = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};

// Intuitive O(1) space:

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* res = root;
        Node* pre = nullptr;
        Node* head = nullptr;
        while (root) {
            if (root->left) {
                if (pre) pre->next = root->left;
                if (!head) head = root->left;
                pre = root->left;
            }
            if (root->right) {
                if (pre) pre->next = root->right;
                if (!head) head = root->right;
                pre = root->right;
            }
            root = root->next;
        }
        connect(head);
        return res;
    }
};
