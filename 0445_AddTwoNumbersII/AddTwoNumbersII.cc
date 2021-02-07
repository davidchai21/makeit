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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int digit = 0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (l1 || l2 || digit) {
            if (l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(digit%10);
            digit /= 10;
            cur = cur->next;
        }
        cur = dummy->next;
        dummy->next = nullptr;
        delete dummy;
        return reverseList(cur);
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

// No input modification:

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLen(l1);
        int len2 = getLen(l2);
        int len = max(len1, len2);
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        for (int i=len-1;i>=0;--i) {
            int val = 0;
            if (i < len1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (i < len2) {
                val += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        dummy->next = reverseList(dummy->next);
        cur = dummy;
        int digit = 0;
        while (cur->next) {
            digit += cur->next->val;
            cur->next->val = digit%10;
            digit /= 10;
            cur = cur->next;
        }
        if (digit) cur->next = new ListNode(1);
        cur = dummy->next;
        dummy->next = nullptr;
        delete dummy;
        return reverseList(cur);
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