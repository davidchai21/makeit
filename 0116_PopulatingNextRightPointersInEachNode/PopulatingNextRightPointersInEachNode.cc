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
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* pre = nullptr;
            for (int i=0;i<size;++i) {
                Node* cur = q.front();
                q.pop();
                if (cur->left) {
                    cur->left->next = cur->right;
                    q.push(cur->left);
                    q.push(cur->right);
                    if (pre && pre->right) pre->right->next = cur->left;
                }
                pre = cur;
            }
        }
        return root;
    }
};

// better intuitive:

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
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;++i) {
                Node* cur = q.front();
                q.pop();
                if (i<size-1) {
                    cur->next = q.front();
                }
                if (cur->left) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
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
        Node* head = nullptr;
        Node* pre = nullptr;
        while (root) {
            if (root->left) {
                root->left->next = root->right;
                if (root->next) root->right->next = root->next->left;
                if (pre && pre->right) pre->right->next = root->left;
                pre = root;
                if (!head) head = root->left;
            }
            root = root->next;
        }
        connect(head);
        return res;
    }
};

// Better O(1) space:

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
        if (root->left) root->left->next = root->right;
        if (root->right && root->next) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};