class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (data.size() == size) return false;
        data.push_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (data.size() == size) return false;
        data.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (data.empty()) return false;
        data.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (data.empty()) return false;
        data.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (data.empty()) return -1;
        return data.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (data.empty()) return -1;
        return data.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return data.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return data.size() == size;
    }
private:
    list<int> data;
    int size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

// Using vector:

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        if (!isEmpty()) {
            head = (head+data.size()-1)%data.size();
        }
        data[head] = value;
        ++size;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        if (!isEmpty()) {
            tail = (tail+1)%data.size();
        }
        data[tail] = value;
        ++size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        if (size > 1) {
            head = (head+1)%data.size();
        }
        --size;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        if (size > 1) {
            tail = (tail+data.size()-1)%data.size();
        }
        --size;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return data[tail];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == data.size();
    }
private:
    vector<int> data;
    int head, tail, size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */