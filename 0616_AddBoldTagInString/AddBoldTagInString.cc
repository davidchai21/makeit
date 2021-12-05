struct Node {
    bool isEnd = false;
    unordered_map<char, Node*> child;
    
    ~Node() {
        for (auto it = child.begin(); it != child.end(); ++it) {
            delete it->second;
            it->second = nullptr;
        }
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        root = new Node();
        build(dict);
        int n = s.size();
        vector<bool> visited(n, false);
        for (int i=0;i<n;++i) {
            int right = search(s, i, n);
            if (right) {
                for (int j=i;j<i+right;++j) {
                    visited[j] = true;
                }
            }
        }
        string res = "";
        bool inside = false;
        for (int i=0;i<n;++i) {
            if (!inside && visited[i]) {
                res += "<b>";
                inside = true;
            } else if (inside && !visited[i]) {
                res += "</b>";
                inside = false;
            }
            res.push_back(s[i]);
        }
        if (inside) res += "</b>";
        return res;
    }
private:
    Node* root;
    
    void build(vector<string>& dict) {
        for (string& s : dict) {
            Node* cur = root;
            for (char& c : s) {
                if (cur->child.find(c) == cur->child.end()) cur->child[c] = new Node();
                cur = cur->child[c];
            }
            cur->isEnd = true;
        }
    }
    
    int search(string& s, int index, const int& n) {
        int res = 0;
        int base = index;
        Node* cur = root;
        while (index < n && cur) {
            if (cur->child.find(s[index]) == cur->child.end()) break;
            cur = cur->child[s[index++]];
            if (cur->isEnd) res = max(res, index-base);
        }
        return res;
    }
};

// Another:

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        set<pair<int,int>> st;
        for (string& d : dict) {
            int n = d.size();
            for (int i=0;(i=s.find(d, i)) != string::npos; ++i) {
                st.insert(make_pair(i, i+n));
            }
        }
        if (st.empty()) return s;
        
        auto it = st.begin();
        vector<pair<int,int>> record;
        while (it != st.end()) {
            if (record.empty() || record.back().second < it->first) {
                record.push_back(*it);
            } else {
                record.back().second = max(it->second, record.back().second);
            }
            ++it;
        }
        
        string res = "";
        int e = 0;
        for (pair<int, int>& cur : record) {
            res += s.substr(e, cur.first-e);
            res += "<b>";
            res += s.substr(cur.first, cur.second-cur.first);
            res += "</b>";
            e = cur.second;
        }
        if (e < s.size()) res += s.substr(e);
        return res;
    }
};