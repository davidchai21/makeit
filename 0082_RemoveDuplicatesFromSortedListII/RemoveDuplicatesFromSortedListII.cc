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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* origin = new ListNode(0);
        origin->next = head;
        ListNode* cur = origin;
        while (cur->next) {
            if (cur->next && cur->next->next && cur->next->val == cur->next->next->val) {
                ListNode* tail = findTail(cur->next->next, cur->next->val);
                cur->next = tail;
            } else {
                cur = cur->next;
            }
        }
        head = origin->next;
        origin->next = nullptr;
        delete origin;
        return head;
    }
private:
    ListNode* findTail(ListNode* head, int val) {
        while (head && head->val == val) head = head->next;
        return head;
    }
};