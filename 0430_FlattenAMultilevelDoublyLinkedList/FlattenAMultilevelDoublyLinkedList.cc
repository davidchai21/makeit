/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* cur = head;
        while (cur) {
            if (cur->child) {
                Node* c = cur->child;
                Node* next = cur->next;
                cur->child = nullptr;
                c->prev = cur;
                cur->next = c;
                while (c->next) c = c->next;
                c->next = next;
                if (next) next->prev = c;
            }
            cur = cur->next;
        }
        return head;
    }
};

// Recursive:

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        helper(head);
        return head;
    }
private:
    pair<Node*, Node*> helper(Node* head) {
        Node* cur = head;
        Node* tail = head;
        while (cur) {
            if (cur->child) {
                pair<Node*, Node*> c = helper(cur->child);
                cur->child = nullptr;
                c.first->prev = cur;
                c.second->next = cur->next;
                if (cur->next) cur->next->prev = c.second;
                cur->next = c.first;
            }
            tail = cur;
            cur = cur->next;
        }
        return make_pair(head, tail);
    }
};