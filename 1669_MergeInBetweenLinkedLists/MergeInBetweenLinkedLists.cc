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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode();
        dummy->next = list1;
        list1 = dummy;
        for (int i=0;i<a;++i) list1 = list1->next;
        ListNode* tail1 = list1;
        for (int i=a;i<=b;++i) tail1 = tail1->next;
        ListNode* tail2 = findTail(list2);
        tail2->next = tail1->next;
        list1->next = list2;
        return dummy->next;
    }
private:
    ListNode* findTail(ListNode* head) {
        while (head->next) head = head->next;
        return head;
    }
};