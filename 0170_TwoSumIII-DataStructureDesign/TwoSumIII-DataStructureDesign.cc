class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++m[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto it = m.begin(); it != m.end(); ++it) {
            long r = (long)value-it->first;
            if (r == it->first) {
                if (it->second > 1) return true;
            } else {
                if (m.find(r) != m.end()) return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> m;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */