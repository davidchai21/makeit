class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        store.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (size == store.size()) return false;
        store[tail] = value;
        tail = (tail+1)%store.size();
        ++size;
        return true;
    }
    
    bool deQueue() {
        if (!size) return false;
        --size;
        head = (head+1)%store.size();
        return true;
    }
    
    int Front() {
        if (!size) return -1;
        return store[head];
    }
    
    int Rear() {
        if (!size) return -1;
        int index = (tail+store.size()-1)%store.size();
        return store[index];
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == store.size();
    }
private:
    vector<int> store;
    int head, tail;
    int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */