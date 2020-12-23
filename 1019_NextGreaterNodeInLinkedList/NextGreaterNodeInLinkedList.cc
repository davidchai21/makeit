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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        int index = 0;
        while (head) {
            while (!st.empty() && res[st.top()] < head->val) {
                res[st.top()] = head->val;
                st.pop();
            }
            st.push(index++);
            res.push_back(head->val);
            head = head->next;
        }
        while (!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};