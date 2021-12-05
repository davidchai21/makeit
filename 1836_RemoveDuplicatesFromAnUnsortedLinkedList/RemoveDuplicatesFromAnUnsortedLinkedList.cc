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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* cur = head;
        unordered_map<int, int> m;
        while (cur) {
            ++m[cur->val];
            cur = cur->next;
        }
        while (head && m[head->val] > 1) {
            head = head->next;
        }
        if (!head) return nullptr;
        
        cur = head;
        while (cur) {
            while (cur->next && m[cur->next->val] > 1) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};