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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int n = lists.size();
        if (n==1) return lists.back();
        
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        for (ListNode*& l : lists) {
            if (l) q.push(l);
        }
        ListNode* res = new ListNode();
        ListNode* cur = res;
        while (!q.empty()) {
            cur->next = q.top();
            cur = cur->next;
            q.pop();
            if (cur->next) q.push(cur->next);
        }
        return res->next;
    }
private:
    struct comp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};