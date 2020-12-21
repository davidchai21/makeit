class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int res = 1;
        while (ss >> word) {
            if (check(word, searchWord)) return res;
            ++res;
        }
        return -1;
    }
private:
    bool check(string& a, string& b) {
        if (a.size()<b.size()) return false;
        for (int i=0;i<b.size();++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};