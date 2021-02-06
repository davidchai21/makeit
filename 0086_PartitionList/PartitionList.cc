/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessNode = new ListNode();
        ListNode* largerNode = new ListNode();
        ListNode *left = lessNode, *right = largerNode;
        while (head) {
            if (head->val < x) {
                lessNode->next = head;
                lessNode = head;
            } else {
                largerNode->next = head;
                largerNode = head;
            }
            head = head->next;
        }
        lessNode->next = right->next;
        largerNode->next = nullptr;
        right->next = nullptr;
        delete right;
        head = left->next;
        left->next = nullptr;
        delete left;
        return head;
    }
};