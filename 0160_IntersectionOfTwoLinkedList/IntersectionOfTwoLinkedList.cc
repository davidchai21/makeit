/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = getLen(headA);
        int n = getLen(headB);
        while (m > n) {
            --m;
            headA = headA->next;
        }
        while (n > m) {
            --n;
            headB = headB->next;
        }
        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
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
};

// Better Solution:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, *b = headB;
        while (a != b) {
            a = a?a->next:headB;
            b = b?b->next:headA;
        }
        return a;
    }
};