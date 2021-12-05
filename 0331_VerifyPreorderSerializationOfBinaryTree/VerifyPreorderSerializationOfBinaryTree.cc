// Recursive:

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string word;
        if (!helper(ss, word)) return false;
        return !getNext(ss, word);
    }
private:
    const char deli = ',';
    bool getNext(stringstream& ss, string& word) {
        if (getline(ss, word, deli)) return true;
        return false;
    }
    
    bool helper(stringstream& ss, string& word) {
        if (!getNext(ss, word)) return false;
        if (word == "#") return true;
        if (!helper(ss, word)) return false;
        if (!helper(ss, word)) return false;
        return true;
    }
};

// Iterative:

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.front() == '#') return preorder.size()==1;
        
        stringstream ss(preorder);
        string word;
        getline(ss, word, deli);
        stack<pair<string, int>> st;
        st.push(make_pair(word, 2));
        while (getline(ss, word, deli)) {
            if (st.empty()) return false;
            --st.top().second;
            if (word != "#") {
                st.push(make_pair(word, 2));
            }
            while (!st.empty() && st.top().second == 0) st.pop();
        }
        return st.empty();
    }
private:
    const char deli = ',';
};

// O(1) space:

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot = 1;
        stringstream ss(preorder);
        string word;
        while (getline(ss, word, deli)) {
            if (word == "#") {
                if (!slot) return false;
                --slot;
            } else {
                if (!slot) return false;
                ++slot;
            }
        }
        return !slot;
    }
private:
    const char deli = ',';
};