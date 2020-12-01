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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        int digit = 0;
        while (l1 || l2 || digit) {
            if (l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2->next;
            }
            if (cur) {
                cur->next = new ListNode(digit%10);
                cur = cur->next;
            } else {
                head = new ListNode(digit%10);
                cur = head;
            }
            digit /= 10;
        }
        return head;
    }
};