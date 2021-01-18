struct Node {
    bool isEnd = false;
    Node* child[26] = {};
    
    Node() {};
    ~Node() {
        for (int i=0;i<26;++i) delete child[i];
    }
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        root = new Node();
        for (string& word : words) build(word);
        for (int i=0;i<text.size();++i) {
            vector<int> curRes = _find(text, i);
            for (int& k : curRes) {
                res.push_back({i, k});
            }
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
    
    vector<int> _find(string& text, int start) {
        vector<int> res;
        Node* cur = root;
        for (int i=start; i<text.size();++i) {
            int pos = text[i] - 'a';
            if (!cur->child[pos]) break;
            cur = cur->child[pos];
            if (cur->isEnd) res.push_back(i);
        }
        return res;
    }
};