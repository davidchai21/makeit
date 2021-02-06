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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        while (head->next) {
            ListNode* node = head->next;
            if (head->val <= node->val) {
                head = node;
                continue;
            }
            head->next = head->next->next;
            ListNode* cur = dummy;
            for (;;) {
                if (cur->val <= node->val && node->val <= cur->next->val) {
                    node->next = cur->next;
                    cur->next = node;
                    break;
                }
                cur = cur->next;
            }
        }
        head = dummy->next;
        dummy->next = nullptr;
        delete dummy;
        return head;
    }
};