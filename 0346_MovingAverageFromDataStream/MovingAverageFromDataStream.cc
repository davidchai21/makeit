class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return (double)sum/q.size();
    }
private:
    queue<int> q;
    int size;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

// Circular Queue:

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        data.resize(size);
        this->size = 0;
        head = 0;
        sum = 0.0;
    }
    
    double next(int val) {
        int tail = (head+size)%data.size();
        sum += val;
        if (head == tail && size) {
            sum -= data[head];
            head = (head+1)%data.size();
        } else ++size;
        data[tail] = val;
        return sum/size;
    }
private:
    int size, head;
    double sum;
    vector<int> data;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */