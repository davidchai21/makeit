class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        size = maxNumbers;
        book.resize(size, false);
        count = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (count == size) return -1;
        int res = 0;
        while (book[res]) ++res;
        book[res] = true;
        ++count;
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !book[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= size) return;
        if (book[number]) {
            book[number] = false;
            --count;
        }
    }
private:
    int size;
    vector<bool> book;
    int count;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

// Another O(1):

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        size = maxNumbers;
        count = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int res = -1;
        if (!free.empty()) {
            res = *free.begin();
            free.erase(res);
        } else if (count < size) {
            res = count++;
        }
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return count <= number || free.find(number) != free.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= size) return;
        if (number < count) free.insert(number);
    }
private:
    unordered_set<int> free;
    int count;
    int size;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */