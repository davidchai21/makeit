class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->child[c-'a']) {
                cur->child[c-'a'] = new Node();
            }
            cur = cur->child[c-'a'];
        }
        cur->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }
        return cur->flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (!cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }
        return true;
    }
private:
    struct Node {
        bool flag;
        Node* child[26] = {};
        
        Node():flag(false) {}
        Node(bool _flag):flag(_flag) {}
    };
    
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */