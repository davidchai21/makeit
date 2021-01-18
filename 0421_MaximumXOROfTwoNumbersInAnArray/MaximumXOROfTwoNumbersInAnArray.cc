struct Node {
    Node* child[2] = {};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        int res = 0;
        for (int& num : nums) {
            build(num);
            res = max(res, _find(num));
        }
        return res;
    }
private:
    Node* root;
    
    void build(int& n) {
        Node* cur = root;
        for (int i=30;i>=0;--i) {
            int pos = n&(1<<i) ? 1 : 0;
            if (!cur->child[pos]) cur->child[pos] = new Node();
            cur = cur->child[pos];
        }
    }
    
    int _find(int& n) {
        Node* cur = root;
        int res = 0;
        for (int i=30;i>=0;--i) {
            int pos = n&(1<<i) ? 0 : 1;
            if (!cur->child[pos]) cur = cur->child[1-pos];
            else {
                cur = cur->child[pos];
                res |= 1<<i;
            }
        }
        return res;
    }
};