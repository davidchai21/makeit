class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        a = A;
        index = 0;
        val = -1;
        count = 0;
        j=0;
    }
    
    int next(int n) {
        if (count == -2) return -1;
        index += n;
        while (index > count) {
            if (j>=a.size()) {
                count = -2;
                return -1;
            }
            val = a[j+1];
            index -= count;
            count = a[j];
            j += 2;
        }
        return val;
    }
private:
    vector<int> a;
    int index;
    int val;
    int count;
    int j;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */

// Iterator:

class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        cur = A.begin(), end = A.end();
        count = 0;
    }
    
    int next(int n) {
        if (count < 0) return -1;
        
        count += n;
        while (count >= 0) {
            if (cur == end) {
                count = -1;
                break;
            }
            if (count > *cur) {
                count -= *cur;
                cur = cur+2;
            } else {
                *cur -= count;
                count = 0;
                return *(cur+1);
            }
        }
        return -1;
    }
private:
    vector<int>::iterator cur, end;
    int count;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */