/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (!head) {
            node->next = node;
            return node;
        }
        
        Node* pre = head;
        Node* cur = head->next;
        Node* maxNode = pre;
        Node* minNode = cur;
        do {
            if (pre->val <= insertVal && insertVal <= cur->val) {
                pre->next = node;
                node->next = cur;
                return head;
            }
            if (pre->val > cur->val) {
                maxNode = pre;
                minNode = cur;
            }
            pre = cur;
            cur = cur->next;
        } while (pre != head);
        
        maxNode->next = node;
        node->next = minNode;
        return head;
    }
};