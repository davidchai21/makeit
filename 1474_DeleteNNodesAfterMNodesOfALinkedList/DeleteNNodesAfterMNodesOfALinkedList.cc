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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        bool flag = false;
        head = dummy;
        while (head->next) {
            if (!flag) {
                for (int i=0;i<m && head->next;++i) {
                    head = head->next;
                }
                flag = true;
            } else {
                for (int i=0;i<n && head->next;++i) {
                    ListNode* node = head->next;
                    head->next = node->next;
                    node->next = nullptr;
                    delete node;
                }
                flag = false;
            }
        }
        head = dummy->next;
        dummy->next = nullptr;
        delete dummy;
        return head;
    }
};