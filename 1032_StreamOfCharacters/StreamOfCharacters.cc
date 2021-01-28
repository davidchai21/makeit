struct Node {
    bool isEnd = false;
    Node* child[26];
    Node() {
        memset(child, 0, sizeof(Node*)*26);
    }
    ~Node() {
        for (int i=0;i<26;++i) {
            free(child[i]);
        }
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new Node();
        for (string& word : words) {
            maxL = max(maxL, word.size());
            addWord(word);
        }
    }
    
    bool query(char letter) {
        dic.push_back(letter);
        if (dic.size() > maxL) dic.pop_front();
        Node* cur = root;
        for (auto it = dic.rbegin(); it != dic.rend(); ++it) {
            if (cur->isEnd) return true;
            int pos = (*it)-'a';
            if (!cur->child[pos]) return false;
            cur = cur->child[pos];
        }
        return cur->isEnd;
    }
private:
    list<char> dic;
    Node* root;
    size_t maxL = 0;
    
    inline void addWord(string& word) {
        Node* cur = root;
        for (int i=word.size()-1;i>=0;--i) {
            int pos = word[i]-'a';
            if (!cur->child[pos]) cur->child[pos] = new Node();
            cur = cur->child[pos];
        }
        cur->isEnd = true;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */