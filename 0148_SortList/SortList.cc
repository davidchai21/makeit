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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = sortList(slow->next);
        slow->next = nullptr;
        slow = sortList(head);
        return merge(slow, fast);
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

// Iterative: 

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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int len = getLen(head);
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *left, *right, *tail = dummy, *cur = head;
        for (int step = 1; step < len; step<<=1) {
            tail = dummy;
            cur = dummy->next;
            while (cur) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        head = dummy->next;
        delete dummy;
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
    
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail) {
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while (tail->next) tail = tail->next;
        return tail;
    }
    
    ListNode* split(ListNode* head, int step) {
        for (int i=1; head && i<step; ++i) {
            head = head->next;
        }
        if (!head) return nullptr;
        ListNode* res = head->next;
        head->next = nullptr;
        return res;
    }
};