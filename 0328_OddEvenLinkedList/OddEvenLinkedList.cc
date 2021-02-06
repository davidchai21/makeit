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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();
        ListNode* cur1 = odd, *cur2 = even;
        while (head && head->next) {
            cur1->next = head;
            cur1 = cur1->next;
            head = head->next;
            cur2->next = head;
            cur2 = cur2->next;
            head = head->next;
        }
        if (head) {
            cur1->next = head;
            cur1 = cur1->next;
        }
        cur1->next = even->next;
        cur2->next = nullptr;
        return odd->next;
    }
};

// Better:

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};