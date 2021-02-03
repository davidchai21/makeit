class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size());
        for (int i=0;i<queries.size();++i) {
            res[i] = helper(queries[i], pattern);
        }
        return res;
    }
private:
    bool helper(string& word, string& pattern) {
        int index = 0;
        for (int i=0;i<word.size();++i) {
            if (index == pattern.size()) {
                if (isCap(word[i])) return false;
                else continue;
            }
            bool wordCap = isCap(word[i]);
            bool patCap = isCap(pattern[index]);
            if (wordCap && patCap) {
                if (word[i] != pattern[index]) return false;
                else ++index;
            } else if (wordCap && !patCap) return false;
            else if (!wordCap && patCap) continue;
            else {
                if (word[i] == pattern[index]) ++index;
            }
        }
        return index == pattern.size();
    }
    
    bool isCap(char& c) {
        return c>='A' && c<='Z';
    }
};

// Shorter:

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size());
        for (int i=0;i<queries.size();++i) {
            res[i] = helper(queries[i], pattern);
        }
        return res;
    }
private:
    bool helper(string& word, string& pattern) {
        int index = 0;
        for (char& c : word) {
            if (index == pattern.size() && isupper(c)) return false;
            if (c==pattern[index]) ++index;
            else if (isupper(c)) return false;
        }
        return index == pattern.size();
    }
};