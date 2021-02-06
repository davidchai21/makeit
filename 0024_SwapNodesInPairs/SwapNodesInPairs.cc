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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = next->next->next;
            cur->next->next = next;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};

// Recursive:

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = second->next;
        second->next = first;
        first->next = swapPairs(first->next);
        return second;
    }
};