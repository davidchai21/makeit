// Direct:

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* origin = new ListNode(0);
        ListNode* cur = origin;
        origin->next = head;
        while (head) {
            if (!n) cur = cur->next;
            else --n;
            head = head->next;
        }
        cur->next = cur->next->next;
        head = origin->next;
        origin->next = nullptr;
        delete origin;
        return head;
    }
};


// Pointer:

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** root = &head;
        ListNode* tail = head;
        while (--n) tail = tail->next;
        while (tail->next) {
            tail = tail->next;
            root = &((*root)->next);
        }
        *root = (*root)->next;
        return head;
    }
};