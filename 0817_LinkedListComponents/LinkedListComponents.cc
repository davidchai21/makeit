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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int res = 0;
        bool flag = false;
        while (head) {
            if (s.find(head->val) != s.end()) {
                if (!flag) {
                    flag = true;
                    ++res;
                }
            } else flag = false;
            head = head->next;
        }
        return res;
    }
};