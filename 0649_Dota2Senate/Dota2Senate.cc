struct Node {
    char val;
    Node* next;
    Node* prev;
    
    Node(char _val): val(_val) {
        next = nullptr;
        prev = nullptr;
    }
    ~Node() {
        next = nullptr;
        prev = nullptr;
        delete next;
        delete prev;
    }
};

class Solution {
public:
    string predictPartyVictory(string senate) {
        root = build(senate);
        Node* cur = root;
        for (;;) {
            Node* node = cur->next;
            while (node != cur && node->val == cur->val) node = node->next;
            if (node == cur) break;
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
            cur = cur->next;
        }
        return cur->val == 'R' ? "Radiant" : "Dire";
    }
private:
    Node* root;
    
    Node* build(string& senate) {
        Node* head = new Node(senate.front());
        Node* cur = head;
        for (int i=1;i<senate.size();++i) {
            Node* node = new Node(senate[i]);
            cur->next = node;
            node->prev = cur;
            cur = node;
        }
        cur->next = head;
        head->prev = cur;
        return head;
    }
};

// Better:

class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = 0, count = 0;
        while (len != senate.size()) {
            string s = "";
            len = senate.size();
            for (char& c : senate) {
                if (c=='R') {
                    if (count++ >= 0) {
                        s.push_back(c);
                    }
                } else {
                    if (count-- <= 0) {
                        s.push_back(c);
                    }
                }
            }
            s.swap(senate);
        }
        return senate.front() == 'R' ? "Radiant" : "Dire";
    }
};