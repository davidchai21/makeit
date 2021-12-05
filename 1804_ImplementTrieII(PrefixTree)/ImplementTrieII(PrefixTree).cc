struct Node {
    int equal = 0;
    int start = 1;
    Node* child[26];
    Node() {
        for (int i=0;i<26;++i) {
            child[i] = nullptr;
        }
    }
    ~Node() {
        for (int i=0;i<26;++i) {
            delete child[i];
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (char& c : word) {
            int pos = c-'a';
            if (!cur->child[pos]) cur->child[pos] = new Node();
            else ++cur->child[pos]->start;
            cur = cur->child[pos];
        }
        ++cur->equal;
    }
    
    int countWordsEqualTo(string word) {
        Node* cur = root;
        for (char& c : word) {
            int pos = c-'a';
            if (!cur->child[pos]) return 0;
            cur = cur->child[pos];
        }
        return cur->equal;
    }
    
    int countWordsStartingWith(string prefix) {
        Node* cur = root;
        for (char& c : prefix) {
            int pos = c-'a';
            if (!cur->child[pos]) return 0;
            cur = cur->child[pos];
        }
        return cur->start;
    }
    
    void erase(string word) {
        Node* cur = root;
        for (char& c : word) {
            int pos = c-'a';
            cur = cur->child[pos];
            --cur->start;
        }
        --cur->equal;
    }
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */ 