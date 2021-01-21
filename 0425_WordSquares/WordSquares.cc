class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words[0].size();
        unordered_map<char, vector<string>> m;
        for (string& word : words) m[word[0]].push_back(word);
        vector<vector<string>> res;
        for (string& word : words) {
            vector<string> record({word});
            helper(record, res, word, 1, m);
        }
        return res;
    }
private:
    void helper(vector<string>& record, vector<vector<string>>& res, string& word, int index, unordered_map<char, vector<string>>& m) {
        if (index == word.size()) {
            res.push_back(record);
            return;
        }
        
        char c = word[index];
        for (int i=0;i<m[c].size();++i) {
            if (check(index, record, m[c][i])) {
                record.push_back(m[c][i]);
                helper(record, res, word, index+1, m);
                record.pop_back();
            }
        }
    }
    
    bool check(int& index, vector<string>& record, string& cur) {
        for (int i=0;i<index;++i) {
            if (cur[i] != record[i][index]) return false;
        }
        return true;
    }
};

// Trie: 

struct Node {
    vector<int> prefix;
    Node* child[26];
    
    Node() {
        memset(child, 0, sizeof(child));
    }
    
    ~Node() {
        for (int i=0;i<26;++i) {
            free(child[i]);
        }
    }
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        root = new Node();
        for (int i=0;i<words.size();++i) {
            build(words[i], i);
        }
        
        vector<vector<string>> res;
        vector<string> record(words[0].size());
        for (string& word : words) {
            record[0] = word;
            _find(res, record, words, 1);
        }
        return res;
    }
private:
    Node* root;
    
    void build(string& word, int& index) {
        Node* cur = root;
        for (char& c : word) {
            int pos = c-'a';
            if (!cur->child[pos]) cur->child[pos] = new Node();
            cur = cur->child[pos];
            cur->prefix.push_back(index);
        }
    }
    
    void _find(vector<vector<string>>& res, vector<string>& record, vector<string>& words, int index) {
        if (index >= record.size()) {
            res.push_back(record);
            return;
        }
        
        Node* cur = root;
        for (int i=0;i<index;++i) {
            int pos = record[i][index] - 'a';
            if (!cur->child[pos]) return;
            cur = cur->child[pos];
        }
        for (int i=0;i<cur->prefix.size();++i) {
            record[index] = words[cur->prefix[i]];
            _find(res, record, words, index+1);
        }
    }
};