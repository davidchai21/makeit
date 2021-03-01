class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        ++count[x];
        if (count[x] > maxFreq) {
            maxFreq = count[x];
            freq[maxFreq].push(x);
        } else {
            freq[count[x]].push(x);
        }
    }
    
    int pop() {
        int res = freq[maxFreq].top();
        --count[res];
        freq[maxFreq].pop();
        if (freq[maxFreq].empty()) {
            freq.erase(maxFreq);
            --maxFreq;
        }
        return res;
    }
private:
    int maxFreq;
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */