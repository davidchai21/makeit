class Solution {
public:
    bool isNumber(string s) {
        int pos = countE(s);
        if (pos == s.size()) return false;
        if (pos == -1) return checkDecimal(s) || checkInteger(s);
        return (checkDecimal(s.substr(0, pos)) || checkInteger(s.substr(0, pos))) && checkInteger(s.substr(pos+1));
    }
private:
    inline int countE(const string& s) {
        int res = -1;
        for (int i=0;i<s.size();++i) {
            if (s[i] == 'E' || s[i] == 'e') {
                if (res == -1) res = i;
                else return s.size();
            }
        }
        return res;
    }
    
    bool checkDecimal(string s) {
        if (s.empty()) return false;
        int index = (s.front() == '+' || s.front() == '-') ? 1 : 0;
        int n = s.size();
        int prefix = 0, suffix = 0;
        bool foundDot = false;
        for (;index < n; ++index) {
            if (isdigit(s[index])) {
                foundDot ? ++suffix : ++prefix;
            } else {
                if (s[index] == '.') {
                    if (foundDot) return false;
                    foundDot = true;
                } else return false;
            }
        }
        return foundDot && (prefix || suffix);
    }
    
    bool checkInteger(string s) {
        if (s.empty()) return false;
        int index = 0;
        int n = s.size();
        if (s.front() == '+' || s.front() == '-') ++index;
        int count = 0;
        for (;index < n;++index) {
            if (isdigit(s[index])) ++count;
            else return false;
        }
        return count;
    }
};