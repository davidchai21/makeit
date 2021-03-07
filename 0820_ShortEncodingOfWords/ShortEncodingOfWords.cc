// Trie:

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

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        _root = new Node();
        for (string& word : words) {
            addWord(word);
        }
        int res = 0;
        string s = "";
        search(_root, s, res);
        return res;
    }
private:
    Node* _root;
    
    void addWord(string& word) {
        Node* cur = _root;
        for (auto it = word.rbegin(); it != word.rend(); ++it) {
            int pos = *it - 'a';
            if (!cur->child[pos]) cur->child[pos] = new Node();
            cur = cur->child[pos];
        }
        cur->isEnd = true;
    }
    
    bool search(Node* root, string& s, int& res) {
        if (!root) return false;
        int count = 0;
        for (int i=0;i<26;++i) {
            s.push_back(i+'a');
            if (search(root->child[i], s, res)) ++count;
            s.pop_back();
        }
        if (!count && root->isEnd) res += s.size()+1;
        return count || root->isEnd;
    }
};