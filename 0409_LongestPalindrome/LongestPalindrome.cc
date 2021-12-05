class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> record(128, 0);
        for (char& c : s) ++record[c];
        bool odd = false;
        int res = 0;
        for (int i=1;i<128;++i) {
            res += record[i]/2;
            if (record[i]&1) odd = true;
        }
        return res*2 + odd;
    }
};

// hashmap:

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char& c : s) ++m[c];
        int res = 0;
        bool odd = false;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res += it->second/2;
            if (it->second & 1) odd = true;
        }
        return res*2 + odd;
    }
};