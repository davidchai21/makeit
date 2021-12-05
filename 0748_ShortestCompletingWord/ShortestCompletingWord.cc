class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> stat(26, 0);
        string res = "";
        for (char& c : licensePlate) {
            if (isalpha(c)) ++stat[tolower(c)-'a'];
        }
        for (string& word : words) {
            if (check(word, stat)) {
                if (res.empty() || res.size() > word.size()) res = word; 
            }
        }
        return res;
    }
private:
    bool check(string& s, const vector<int>& stat) {
        vector<int> t(26, 0);
        for (char& c : s) ++t[c-'a'];
        for (int i=0;i<26;++i) {
            if (t[i] < stat[i]) return false;
        }
        return true;
    }
};