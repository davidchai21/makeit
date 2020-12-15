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
    ListNode* plusOne(ListNode* head) {
        head = revert(head);
        int bit = 1;
        ListNode* cur = head;
        while (bit) {
            bit += cur->val;
            cur->val = bit%10;
            bit /= 10;
            if (!cur->next) break;
            cur = cur->next;
        }
        if (bit) cur->next = new ListNode(1);
        return revert(head);
    }
private:
    ListNode* revert(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

// no reverse:

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
    ListNode* plusOne(ListNode* head) {
        ListNode* notNine = nullptr;
        ListNode* cur = head;
        while (cur) {
            if (cur->val != 9) notNine = cur;
            cur = cur->next;
        }
        if (notNine) {
            ++notNine->val;
            notNine = notNine->next;
            while (notNine) {
                notNine->val = 0;
                notNine = notNine->next;
            }
        } else {
            notNine = head;
            while (notNine) {
                notNine->val = 0;
                notNine = notNine->next;
            }
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
    }
};