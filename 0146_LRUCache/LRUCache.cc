class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        int res = m[key]->val;
        moveToHead(key);
        return res;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->val = value;
            moveToHead(key);
        } else {
            Node* node = new Node(key, value);
            m[key] = node;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            if (m.size() > capacity) {
                int k = tail->prev->key;
                m.erase(k);
                removeTail();
            }
        }
    }
private:
    struct Node {
        int key = 0;
        int val = 0;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        Node() {}
        Node(int _key, int _val): key(_key), val(_val) {}
    };
    
    int capacity;
    unordered_map<int, Node*> m;
    Node* head, *tail;
    
    void moveToHead(int key) {
        Node* cur = m[key];
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        cur->next = head->next;
        cur->next->prev = cur;
        cur->prev = head;
        head->next = cur;
    }
    
    void removeTail() {
        Node* cur = tail->prev;
        tail->prev = cur->prev;
        cur->prev->next = tail;
        cur->next = cur->prev = nullptr;
        delete cur;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */