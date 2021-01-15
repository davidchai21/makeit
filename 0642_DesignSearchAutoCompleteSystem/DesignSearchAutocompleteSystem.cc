struct TrieNode {
    string str = "";
    int time = 0;
    unordered_map<char, TrieNode*> child;
    
    TrieNode() {};
    TrieNode(string _str): str(_str) {};
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i=0;i<times.size();++i) {
            _add(sentences[i], times[i]);
        }
        s = "";
        cur = root;
    }
    
    vector<string> input(char c) {
        vector<string> res;
        if (c == '#') {
            _add(s, 1);
            s = "";
            cur = root;
            return res;
        }
        
        s += c;
        if (cur && cur->child.find(c) != cur->child.end()) {
            cur = cur->child[c];
        } else {
            cur = nullptr;
            return {};
        }
        
        pq = priority_queue<pair<string, int>, vector<pair<string, int>>, cmp>();
        _find(cur);
        while (res.size() < 3 && !pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
private:
    TrieNode* root, *cur;
    string s;
    
    struct cmp {
        bool operator() (pair<string, int>& a, pair<string, int>& b) {
            return a.second < b.second || a.second == b.second && a.first > b.first;
        }
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    
    void _add(string& str, int times) {
        TrieNode* _cur = root;
        for (char& c : str) {
            if (_cur->child.find(c) == _cur->child.end()) _cur->child[c] = new TrieNode();
            _cur = _cur->child[c];
        }
        _cur->time += times;
        _cur->str = str;
    }
    
    void _find(TrieNode* curr) {
        if (!curr) return;
        if (curr->time) pq.emplace(curr->str, curr->time);
        for (auto it = curr->child.begin(); it != curr->child.end(); ++it) {
            _find(it->second);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */