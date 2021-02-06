/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* cur = head;
        while (cur) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        Node* res = head->next;
        cur = head;
        Node* newCur = head->next;
        while (cur) {
            newCur = cur->next;
            if (cur->random) newCur->random = cur->random->next;
            cur = newCur->next;
        }
        cur = head;
        while (cur) {
            newCur = cur->next;
            cur->next = newCur->next;
            cur = cur->next;
            if (cur) newCur->next = cur->next;
        }
        return res;
    }
};

// mapping:

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> m;
        Node* cur = head;
        while (cur) {
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }
        
        cur = head;
        while (cur) {
            if (cur->next) m[cur]->next = m[cur->next];
            if (cur->random) m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};