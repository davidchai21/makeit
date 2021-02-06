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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = getLen(head);
        k = k%len;
        if (!k) return head;
        head = reversePart(head, nullptr);
        ListNode* cur = head;
        while (--k) cur = cur->next;
        cur->next = reversePart(cur->next, nullptr);
        head = reversePart(head, cur->next);
        return head;
    }
private:
    int getLen(ListNode* head) {
        int res = 0;
        while (head) {
            ++res;
            head = head->next;
        }
        return res;
    }
    
    ListNode* reversePart(ListNode* head, ListNode* tail) {
        ListNode* pre = tail;
        ListNode* next = nullptr;
        while (head != tail) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};