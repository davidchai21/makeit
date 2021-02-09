class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n==1) return false;
        int limit = sqrt(n);
        for (int i=1;i<=limit;++i) {
            if (n%i==0) {
                int r = n/i;
                string base = s.substr(0, i);
                int j=1;
                for (;j<r;++j) {
                    if (s.substr(j*i, i) != base) break;
                }
                if (j==r) return true;
                if (i!=1) {
                    base = s.substr(0, r);
                    j=1;
                    for (;j<i;++j) {
                        if (s.substr(j*r, r) != base) break;
                    }
                    if (j==i) return true;
                }
            }
        }
        return false;
    }
};

// Short:

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string d = s+s;
        return d.substr(1, s.size()*2-2).find(s) != string::npos;
    }
};

// gcd:

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size()==1) return false;
        unordered_map<char, int> m;
        for (char& c : s) ++m[c];
        if (m.size()==1) return true;
        int g = -1;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (g==-1) g = it->second;
            else g = gcd(g, it->second);
            if (g==1) return false;
        }
        g = s.size()/g;
        int len = g;
        while (len <= s.size()/2) {
            string base = s.substr(0, len);
            int i = len;
            for (;i<s.size();i+=len) {
                if (s.substr(i,len) != base) break;
            } 
            if (i==s.size()) return true;
            do {
                len += g;
            } while (len <= s.size()/2 && s.size()%len);
        }
        return false;
    }
private:
    int gcd(int a, int b) {
        if (a < b) return gcd(b, a);
        if (a%b==0) return b;
        return gcd(a-b, b);
    }
};