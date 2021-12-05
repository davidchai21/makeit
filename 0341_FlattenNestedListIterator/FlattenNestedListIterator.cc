/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger& k : nestedList) flatten(k);
        index = 0;
    }
    
    int next() {
        return record[index++];
    }
    
    bool hasNext() {
        return index < record.size();
    }
private:
    vector<int> record;
    int index;
    
    void flatten(NestedInteger& n) {
        if (n.isInteger()) record.push_back(n.getInteger());
        else {
            for (NestedInteger& child : n.getList()) {
                flatten(child);
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// stack:

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i=nestedList.size()-1;i>=0;--i) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int res = st.top().getInteger();
        st.pop();
        return res;
    }
    
    bool hasNext() {
        findNext();
        return !st.empty();
    }
private:
    stack<NestedInteger> st;
    
    void findNext() {
        while (!st.empty() && !st.top().isInteger()) {
            NestedInteger cur = st.top();
            st.pop();
            for (auto it = cur.getList().rbegin(); it != cur.getList().rend(); ++it) {
                st.push(*it);
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// stack2:

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i=nestedList.size()-1;i>=0;--i) {
            st.push(&nestedList[i]);
        }
    }
    
    int next() {
        int res = st.top()->getInteger();
        st.pop();
        return res;
    }
    
    bool hasNext() {
        findNext();
        return !st.empty();
    }
private:
    stack<NestedInteger*> st;
    
    void findNext() {
        while (!st.empty() && !st.top()->isInteger()) {
            vector<NestedInteger>& cur = st.top()->getList();
            st.pop();
            for (int i=cur.size()-1;i>=0;--i) {
                st.push(&cur[i]);
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */