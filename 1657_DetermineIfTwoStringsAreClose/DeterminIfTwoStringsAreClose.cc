class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> dic1(26, 0), dic2(26, 0);
        unordered_set<char> s1, s2;
        for (char& c : word1) {
            ++dic1[c-'a'];
            s1.insert(c);
        }
        for (char& c : word2) {
            ++dic2[c-'a'];
            s2.insert(c);
        }
        if (s1 != s2) return false;
        sort(dic1.begin(), dic1.end());
        sort(dic2.begin(), dic2.end());
        return dic1 == dic2;
    }
};

// Using vector only:

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> dic1(26, 0), dic2(26, 0);
        for (char& c : word1) ++dic1[c-'a'];
        for (char& c : word2) ++dic2[c-'a'];
        
        for (int i=0;i<26;++i) {
            if (dic1[i] && !dic2[i] || !dic1[i] && dic2[i]) return false;
        }
        sort(dic1.begin(), dic1.end());
        sort(dic2.begin(), dic2.end());
        return dic1 == dic2;
    }
};

// using bit:

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> dic1(26, 0), dic2(26, 0);
        int bit1 = 0, bit2 = 0;
        for (char& c : word1) {
            ++dic1[c-'a'];
            bit1 |= 1<<(c-'a');
        }
        for (char& c : word2) {
            ++dic2[c-'a'];
            bit2 |= 1<<(c-'a');
        }
        if (bit1 != bit2) return false;
        
        sort(dic1.begin(), dic1.end());
        sort(dic2.begin(), dic2.end());
        return dic1 == dic2;
    }
};

// full bit manipulation:

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> dic1(26, 0), dic2(26, 0);
        int bit1 = 0, bit2 = 0;
        for (char& c : word1) {
            ++dic1[c-'a'];
            bit1 |= 1<<(c-'a');
        }
        for (char& c : word2) {
            ++dic2[c-'a'];
            bit2 |= 1<<(c-'a');
        }
        if (bit1 != bit2) return false;
        
        int value = 0;
        for (int i=0;i<26;++i) {
            value ^= dic1[i];
            value ^= dic2[i];
        }
        return !value;
    }
};