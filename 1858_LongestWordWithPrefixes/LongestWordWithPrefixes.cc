struct Node {
    bool isEnd = false;
    unordered_map<char, Node*> child;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs){
            return lhs.size() < rhs.size() || lhs.size() == rhs.size() && lhs < rhs;
        });
        if (words.front().size() > 1) return "";
        
        root = new Node();
        string res = "";
        for (string& word : words) {
            if (build(word)) {
                if (word.size() > res.size()) res = word;
            }
        }
        return res;
    }
private:
    Node* root;
    
    bool build(string& word) {
        Node* cur = root;
        bool res = true;
        for (int i=0;i<word.size();++i) {
            if (cur->child.find(word[i]) == cur->child.end()) {
                cur->child[word[i]] = new Node();
            }
            cur = cur->child[word[i]];
            if (i != word.size()-1 && !cur->isEnd) res = false;
        }
        cur->isEnd = true;
        return res;
    }
};