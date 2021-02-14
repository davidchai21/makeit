class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (ms.empty()) ms.push(x);
        else ms.push(min(ms.top(), x));
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
private:
    stack<int> s, ms;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Save some space:

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (ms.empty()) ms.emplace(x,1);
        else {
            if (x < ms.top().first) ms.emplace(x,1);
            else ++ms.top().second;
        }
    }
    
    void pop() {
        s.pop();
        --ms.top().second;
        if (ms.top().second == 0) ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top().first;
    }
private:
    stack<int> s;
    stack<pair<int,int>> ms;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */