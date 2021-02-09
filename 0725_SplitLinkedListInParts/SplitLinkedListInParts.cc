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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = getLen(root);
        int offset = n%k;
        int len = n/k;
        ListNode* dummy = new ListNode();
        dummy->next = root;
        root = dummy;
        vector<ListNode*> res(k, nullptr);
        for (int i=0;i<k;++i) {
            ListNode* tail = root;
            for (int j=0;j<len;++j) tail = tail->next;
            if (offset) {
                tail = tail->next;
                --offset;
            }
            res[i] = root->next;
            root->next = nullptr;
            root = tail;
        }
        delete dummy;
        return res;
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
};