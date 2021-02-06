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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        fast = slow->next;
        slow = head;
        while (fast) {
            if (slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
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