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

// Divide and Conquer:

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
        int size = lists.size();
        while (size > 1) {
            for (int i=0;i<size;i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 < size ? lists[i+1] : nullptr;
                lists[i/2] = merge(l1, l2);
            }
            size = (size+1)/2;
        }
        return lists.front();
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
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