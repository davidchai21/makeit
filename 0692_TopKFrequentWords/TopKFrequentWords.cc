class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string& word : words) ++m[word];
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> q;
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push(make_pair(it->first, it->second));
            if (q.size() > k) q.pop();
        }
        
        vector<string> res(k);
        while (--k>=0) {
            res[k] = q.top().first;
            q.pop();
        }
        return res;
    }
private:
    struct comp {
        bool operator() (pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        }
    };
};

// Trie:

struct Node {
    Node* child[26];
    int count = 0;
    
    Node() {
        memset(child, 0, sizeof(Node*)*26);
    }
    ~Node() {
        for (int i=0;i<26;++i) {
            free(child[i]);
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        root = vector<Node*>(words.size()+1, nullptr);
        for (int i=0;i<root.size();++i) root[i] = new Node();
        unordered_map<string, int> m;
        for (string& word : words) ++m[word];
        for (auto it = m.begin(); it != m.end(); ++it) {
            addWord(it->first, it->second);
        }
        
        vector<string> res;
        int index = words.size();
        string s = "";
        while (res.size() < k) {
            helper(res, root[index], s, k);
            --index;
        }
        return res;
    }
private:
    vector<Node*> root;
    
    inline void addWord(const string& word, int& frequency) {
        Node* cur = root[frequency];
        for (const char& c : word) {
            int pos = c-'a';
            if (!cur->child[pos]) cur->child[pos] = new Node();
            cur = cur->child[pos];
        }
        cur->count = frequency;
    }
    
    inline void helper(vector<string>& res, Node* curRoot, string& s, int k) {
        if (!curRoot || res.size() >= k) return;
        if (curRoot->count) {
            res.push_back(s);
        }
        for (int i=0;i<26;++i) {
            s.push_back('a'+i);
            helper(res, curRoot->child[i], s, k);
            s.pop_back();
        }
    }
};