struct Node {
    vector<int> index;
    Node* child[26];
    
    Node() {
        memset(child, 0, sizeof(Node*)*26);
    }
    ~Node() {
        for (int i=0;i<26;++i) {
            free(child[i]);
        }
    }
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        pre = new Node();
        post = new Node();
        for (int i=0;i<words.size();++i) {
            addWords(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        Node* _pre = pre;
        Node* _post = post;
        for (char& c : prefix) {
            int pos = c-'a';
            if (!_pre->child[pos]) return -1;
            _pre = _pre->child[pos];
        }
        for (int i=suffix.size()-1;i>=0;--i) {
            int pos = suffix[i]-'a';
            if (!_post->child[pos]) return -1;
            _post = _post->child[pos];
        }
        int i=_pre->index.size()-1;
        int j=_post->index.size()-1;
        while (i>=0 && j>=0) {
            if (_pre->index[i] == _post->index[j]) return _pre->index[i];
            else if (_pre->index[i] > _post->index[j]) --i;
            else --j;
        }
        return -1;
    }
private:
    Node* pre, *post;
    
    inline void addWords(string& word, int idx) {
        Node* _pre = pre;
        Node* _post = post;
        int n = word.size();
        for (int i=0;i<n;++i) {
            _pre->index.push_back(idx);
            _post->index.push_back(idx);
            int pre_pos = word[i]-'a';
            int post_pos = word[n-1-i]-'a';
            if (!_pre->child[pre_pos]) _pre->child[pre_pos] = new Node();
            if (!_post->child[post_pos]) _post->child[post_pos] = new Node();
            _pre = _pre->child[pre_pos];
            _post = _post->child[post_pos];
        }
        _pre->index.push_back(idx);
        _post->index.push_back(idx);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */