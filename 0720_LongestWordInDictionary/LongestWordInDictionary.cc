struct Node {
    bool isEnd = false;
    Node* child[26] = {};
    
    ~Node() {
        for (int i=0;i<26;++i) delete child[i];
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        root = new Node();
        for (string& word : words) {
            build(word);
        }
        for (int i=0;i<26;++i) {
            _find(root->child[i], string(1, 'a'+i), res);
        }
        return res;
    }
private:
    Node* root;
    
    void build(string& word) {
        Node* cur = root;
        for (char& c : word) {
            int pos = c-'a';
            if (!cur->child[pos]) cur->child[pos] = new Node();
            cur = cur->child[pos];
        }
        cur->isEnd = true;
    }
    
    void _find(Node* node, string s, string& res) {
        if (!node || !node->isEnd) return;
        if (node->isEnd) {
            if (s.size() > res.size()) res = s;
        }
        
        for (int i=0;i<26;++i) {
            _find(node->child[i], s+string(1,'a'+i), res);
        }
    }
};