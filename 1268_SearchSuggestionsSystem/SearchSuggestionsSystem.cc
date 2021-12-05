struct Node {
    bool isEnd = false;
    vector<Node*> child;
    
    Node() {
        child.resize(26, nullptr);
    }
    ~Node() {
        for (int i=0;i<26;++i) {
            delete child[i];
            child[i] = nullptr;
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();
        build(products);
        
        string word = "";
        vector<vector<string>> res;
        Node* cur = root;
        for (char& c : searchWord) {
            word.push_back(c);
            vector<string> save;
            if (cur) {
                cur = cur->child[c-'a'];
                string t = word;
                dfs(save, t, cur);
            }
            res.push_back(save);
        }
        return res;
    }
private:
    Node* root;
    
    void build(vector<string>& ps) {
        for (string& p : ps) {
            Node* cur = root;
            for (char& c : p) {
                int pos = c-'a';
                if (!cur->child[pos]) cur->child[pos] = new Node();
                cur = cur->child[pos];
            }
            cur->isEnd = true;
        }
    }
    
    void dfs(vector<string>& res, string& s, Node* cur) {
        if (res.size() == 3 || !cur) return;
        
        if (cur->isEnd) res.push_back(s);
        for (int i=0;i<26;++i) {
            s.push_back('a'+i);
            dfs(res, s, cur->child[i]);
            s.pop_back();
        }
    }
};

// Binary Search:

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        bool flag = true;
        string word = "";
        for (char& c : searchWord) {
            res.push_back({});
            if (!flag) continue;
            word.push_back(c);
            int index = search(products, word);
            while (index < products.size() && res.back().size() < 3 && startWith(products[index], word)) {
                res.back().push_back(products[index++]);
            }
        }
        return res;
    }
private:
    bool startWith(string& s, string& prefix) {
        if (s.size() < prefix.size()) return false;
        
        for (int i=0;i<prefix.size();++i) {
            if (s[i] != prefix[i]) return false;
        }
        return true;
    }
    
    int search(vector<string>& words, string& prefix) {
        int left = 0, right = words.size();
        while (left < right) {
            int mid = (left + right)/2;
            if (words[mid] < prefix) left = mid+1;
            else right = mid;
        }
        return left;
    }
};

// Two-pointer:

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string word = "";
        int left = 0, right = products.size()-1;
        vector<vector<string>> res;
        for (char& c : searchWord) {
            res.push_back({});
            word.push_back(c);
            while (left <= right && products[left] < word) ++left;
            while (left <= right && products[right].substr(0, word.size()) > word) --right;
            for (int i=left;i<=right && i-left < 3; ++i) {
                res.back().push_back(products[i]);
            }
        }
        return res;
    }
};