class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        size_t pos = dq.size()/2;
        dq.insert(dq.begin()+pos, val);
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        if (dq.empty()) return -1;
        int res = dq.front();
        dq.pop_front();
        return res;
    }
    
    int popMiddle() {
        if (dq.empty()) return -1;
        size_t pos = (dq.size()-1)/2;
        int res = *(dq.begin()+pos);
        dq.erase(dq.begin()+pos);
        return res;
    }
    
    int popBack() {
        if (dq.empty()) return -1;
        int res = dq.back();
        dq.pop_back();
        return res;
    }
private:
    deque<int> dq;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

// Better O(1) solution:

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        left.push_front(val);
        l2r();
    }
    
    void pushMiddle(int val) {
        l2r();
        left.push_back(val);
    }
    
    void pushBack(int val) {
        right.push_back(val);
        r2l();
    }
    
    int popFront() {
        r2l();
        if (left.empty()) return -1;
        int res = left.front();
        left.pop_front();
        return res;
    }
    
    int popMiddle() {
        r2l();
        if (left.empty()) return -1;
        int res = left.back();
        left.pop_back();
        return res;
    }
    
    int popBack() {
        l2r();
        if (right.empty()) return -1;
        int res = right.back();
        right.pop_back();
        return res;
    }
private:
    deque<int> left, right;
    void l2r() {
        while (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
    }
    void r2l() {
        while (right.size() > left.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */