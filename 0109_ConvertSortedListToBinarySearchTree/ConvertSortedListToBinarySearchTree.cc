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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return helper(nums, 0, nums.size()-1);
    }
private:
    TreeNode* helper(vector<int>& nums, int begin, int end) {
        if (begin > end) return nullptr;
        int mid = begin + (end-begin)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, begin, mid-1);
        root->right = helper(nums, mid+1, end);
        return root;
    }
};

// Save space:

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tail = head;
        while (tail && tail->next) tail = tail->next;
        return helper(head, tail);
    }
private:
    TreeNode* helper(ListNode* begin, ListNode* end) {
        if (!begin || end->next == begin) return nullptr;
        if (begin == end) return new TreeNode(begin->val);
        ListNode* slow = begin, *fast = begin->next;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->next->val);
        root->left = helper(begin, slow);
        root->right = helper(slow->next->next, end);
        return root;
    }
};