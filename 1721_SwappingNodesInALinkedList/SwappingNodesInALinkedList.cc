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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* res = head;
        ListNode* first = head;
        ListNode* last = head;
        int counter = 1;
        while (head) {
            if (counter == k) first = head;
            if (counter > k) last = last->next;
            ++counter;
            head = head->next;
        }
        swap(first->val, last->val);
        return res;
    }
};