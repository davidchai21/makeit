class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int _sum = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->first.size() >= prefix.size() && it->first.substr(0,prefix.size()) == prefix) _sum += it->second;
        }
        return _sum;
    }
private:
    unordered_map<string, int> m;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// Trie:

struct TrieNode {
    int val = 0;
    TrieNode* child[26] = {};
    
    TrieNode() {};
    TrieNode(int _val): val(_val) {};
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* cur = root;
        for (char& c : key) {
            if (!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
            cur = cur->child[c-'a'];
        }
        cur->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for (char& c : prefix) {
            if (!cur->child[c-'a']) return 0;
            cur = cur->child[c-'a'];
        }
        return helper(cur);
    }
private:
    TrieNode* root;
    
    int helper(TrieNode* root) {
        if (!root) return 0;
        int sum = root->val;
        for (int i=0;i<26;++i) {
            sum += helper(root->child[i]);
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */