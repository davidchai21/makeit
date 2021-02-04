class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        _size = 0;
        head = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= _size) return -1;
        Node* cur = head;
        for (int i=0;i<index;++i) cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        ++_size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!head) head = node;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        ++_size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size) return;
        if (index == 0) addAtHead(val);
        else if (index == _size) addAtTail(val);
        else {
            Node* cur = head;
            Node* node = new Node(val);
            for (int i=1;i<index;++i) cur = cur->next;
            node->next = cur->next;
            cur->next = node;
            ++_size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size) return;
        if (index == 0) head = head->next;
        else {
            Node* cur = head;
            for (int i=1;i<index;++i) cur = cur->next;
            cur->next = cur->next->next;
        }
        --_size;
    }
private:
    struct Node {
        int val;
        Node* next;
        Node() {
            next = nullptr;
        }
        Node(int _val):val(_val) {
            next = nullptr;
        }
    };
    
    int _size;
    Node* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// Doubly Linked List:

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        if (index <= size/2) {
            Node* cur = head;
            for (int i=0;i<index;++i) cur = cur->next;
            return cur->next->val;
        }
        Node* cur = tail;
        for (int i=size;i>index;--i) cur = cur->prev;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node* node = new Node(val);
        if (index <= size/2) {
            Node* cur = head;
            for (int i=0;i<index;++i) cur = cur->next;
            node->next = cur->next;
            cur->next->prev = node;
            node->prev = cur;
            cur->next = node;
        } else {
            Node* cur = tail;
            for (int i=size;i>index;--i) cur = cur->prev;
            node->prev = cur->prev;
            cur->prev->next = node;
            node->next = cur;
            cur->prev = node;
        }
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index <= size/2) {
            Node* cur = head;
            for (int i=0;i<index;++i) cur = cur->next;
            Node* next = cur->next->next;
            cur->next = next;
            next->prev = cur;
        } else {
            Node* cur = tail;
            for (int i=size-1;i>index;--i) cur = cur->prev;
            Node* prev = cur->prev->prev;
            prev->next = cur;
            cur->prev = prev;
        }
        --size;
    }
private:
    struct Node {
        int val;
        Node* prev, *next;
        
        Node(): val(0), prev(nullptr), next(nullptr) {}
        Node(int _val): val(_val), prev(nullptr), next(nullptr) {}
    };
    
    int size;
    Node* head;
    Node* tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */