struct TrieNode {
    bool isEnd = false;
    TrieNode* child[26] = {};
    
    TrieNode() {};
    TrieNode(bool _isEnd): isEnd(_isEnd) {};
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for (string& word : dictionary) build(word);
        stringstream ss(sentence);
        string word;
        ss >> word;
        string res = find(word);
        while (ss >> word) {
            res += " " + find(word);
        }
        return res;
    }
private:
    TrieNode* root;
    
    void build(string& str) {
        TrieNode* cur = root;
        for (char& c : str) {
            int pos = c-'a';
            if (!cur->child[pos]) cur->child[pos] = new TrieNode();
            cur = cur->child[pos];
        }
        cur->isEnd = true;
    }
    
    string find(string& word) {
        TrieNode* cur = root;
        string res = "";
        for (char& c : word) {
            if (cur->isEnd) return res;
            if (!cur->child[c-'a']) return word;
            cur = cur->child[c-'a'];
            res += c;
        }
        return cur->isEnd ? res : word;
    }
};