class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || *left.rbegin() >= num) {
            left.insert(num);
        } else {
            right.insert(num);
        }
        balance();
    }
    
    double findMedian() {
        if (left.size() > right.size()) return *left.rbegin();
        return (*left.rbegin()+*right.begin())/2.0;
    }
private:
    multiset<int> left, right;
    
    void balance() {
        while (left.size() > right.size()+1) {
            int it = *left.rbegin();
            right.insert(it);
            auto p = left.end();
            --p;
            left.erase(p);
        }
        while (left.size() < right.size()) {
            int num = *right.begin();
            right.erase(right.begin());
            left.insert(num);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Priority_queue:

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        
        while (left.size() > right.size()+1) {
            int t = left.top();
            left.pop();
            right.push(t);
        }
        while (right.size() > left.size()) {
            int t = right.top();
            right.pop();
            left.push(t);
        }
    }
    
    double findMedian() {
        return left.size() > right.size() ? left.top() : (left.top() + right.top())/2.0;
    }
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */