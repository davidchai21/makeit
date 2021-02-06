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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        fast = slow;
        ListNode* pre = head;
        ListNode* node = nullptr;
        while (pre != slow) {
            node = slow->next;
            slow->next = node->next;
            node->next = pre->next;
            pre->next = node;
            pre = node->next;
        }
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};