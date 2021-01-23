class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (abs((long)s.size() - (long)t.size()) > 1) return false;
        if (s.size() < t.size()) return isOneEditDistance(t, s);
        bool changed = false;
        if (s.size() == t.size()) {
            for (int i=0;i<s.size();++i) {
                if (s[i] != t[i]) {
                    if (changed) return false;
                    changed = true;
                }
            }
            return changed;
        }
        int i=0;
        for (;i<t.size();) {
            if (!changed) {
                if (s[i] != t[i]) {
                    changed = true;
                } else ++i;
            } else {
                if (s[i+1] != t[i]) return false;
                else ++i;
            }
        }
        return true;
    }
};

// Another one pass:

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (abs(m-n) > 1) return false;
        
        int i = 0;
        while (i < m && i<n && s[i]==t[i]) ++i;
        if (i==m && i==n) return false;
        if (i==m && i+1==n || i==n && i+1==m) return true;
        
        ++i;
        bool f1 = true, f2 = true, f3 = true;
        while (i<m && i<n) {
            if (s[i-1] != t[i]) f1 = false;
            if (s[i] != t[i]) f2 = false;
            if (t[i-1] != s[i]) f3 = false;
            if (!f1 && !f2 && !f3) return false;
            ++i;
        }
        if (f1 && t[i]==s[i-1] && i+1==n) return true;
        if (f2 && i==n && i==m) return true;
        if (f3 && s[i]==t[i-1] && i+1==m) return true;
        return false;
    }
};