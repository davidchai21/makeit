/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    called = false;
        val = -1;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!called) {
            called = true;
            val = Iterator::next();
        }
        return val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (called) {
            called = false;
            return val;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
	    return called ? true : Iterator::hasNext();
	}
private:
    bool called;
    int val;
};