struct TrieNode {
    bool isEnd = false;
    TrieNode* child[26] = {};
    
    TrieNode() {};
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
            cur = cur->child[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        return helper(cur, word, 0);
    }
private:
    TrieNode* root;
    
    bool helper(TrieNode* node, string& word, int index) {
        if (!node) return false;
        if (index == word.size()) return node->isEnd;
        if (word[index] != '.') return helper(node->child[word[index]-'a'], word, index+1);
        for (int i=0;i<26;++i) {
            if (helper(node->child[i], word, index+1)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */