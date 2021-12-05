class Solution {
public:
    int titleToNumber(string columnTitle) {
        long res = 0L;
        long base = 1L;
        for (int i = columnTitle.size()-1;i>=0;--i) {
            res += base*(columnTitle[i]-'@');
            base *= 26;
        }
        return res;
    }
};

// Shorter:

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char& c : columnTitle) {
            res = res*26+(c-'@');
        }
        return res;
    }
};