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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        head = dummy;
        while (head->next) {
            ListNode* tail = head->next;
            int i=0;
            for (;i<k && tail;++i) tail = tail->next;
            if (i < k) break;
            head->next = reversePart(head->next, tail);
            for (i=0;i<k;++i) head = head->next;
        }
        return dummy->next;
    }
private:
    ListNode* reversePart(ListNode* head, ListNode* tail) {
        ListNode* pre = tail;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur != tail) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};