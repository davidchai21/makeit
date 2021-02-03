struct Node {
    bool isEnd = false;
    Node* child[26];
    Node() {
        memset(child, 0, sizeof(Node*)*26);
    }
    ~Node() {
        for (int i=0;i<26;++i) {
            delete child[i];
        }
    }
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new Node();
    }
    
    void buildDict(vector<string> dictionary) {
        for (string& word : dictionary) {
            Node* cur = root;
            for (char& c : word) {
                int pos = c-'a';
                if (!cur->child[pos]) cur->child[pos] = new Node();
                cur = cur->child[pos];
            }
            cur->isEnd = true;
        }
    }
    
    bool search(string searchWord) {
        return helper(root, 0, searchWord, false);
    }
private:
    Node* root;
    
    bool helper(Node* node, int index, string& word, bool found) {
        if (!node) return false;
        if (index == word.size()) return found && node->isEnd;
        
        if (found) {
            int pos = word[index]-'a';
            return helper(node->child[pos], index+1, word, true);
        } else {
            for (int i=0;i<26;++i) {
                if (helper(node->child[i], index+1, word, word[index]-'a'!=i)) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */