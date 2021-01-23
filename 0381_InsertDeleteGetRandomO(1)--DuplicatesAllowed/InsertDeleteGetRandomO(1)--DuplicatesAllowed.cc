class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = false;
        if (m.find(val) == m.end()) res = true;
        m[val].insert(record.size());
        record.push_back(val);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int back = record.back();
        if (back == val) {
            m[val].erase(record.size()-1);
            if (m[val].empty()) m.erase(val);
            record.pop_back();
            return true;
        }
        int index = *m[val].begin();
        m[val].erase(index);
        if (m[val].empty()) m.erase(val);
        m[back].erase(record.size()-1);
        m[back].insert(index);
        record[index] = back;
        record.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return record[rand()%record.size()];
    }
private:
    vector<int> record;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */