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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* origin = new ListNode(0);
        origin->next = head;
        int sum = 0;
        unordered_map<int, ListNode*> m;
        m[0] = origin;
        while (head) {
            sum += head->val;
            if (m.find(sum) != m.end()) {
                ListNode* cur = m[sum]->next;
                int t_sum = sum;
                while (cur != head) {
                    t_sum += cur->val;
                    m.erase(t_sum);
                    cur = cur->next;
                }
                m[sum]->next = head->next;
            } else {
                m[sum] = head;
            }
            head = head->next;
        }
        return origin->next;
    }
};