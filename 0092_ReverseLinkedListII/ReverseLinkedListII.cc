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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        for (int i=1;i<m;++i) {
            pre = head;
            head = head->next;
        }
        ListNode* left = pre;
        for (int i=m;i<=n;++i) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        left->next->next = head;
        left->next = pre;
        return dummy->next;
    }
};