class Solution {
public:
    string fractionAddition(string expression) {
        unordered_map<int, int> m;
        int n = 0, d = 0;
        int mark = 1;
        int* cur = &n;
        for (char& c : expression) {
            if (c == '+' || c=='-') {
                if (n) m[d] += n*mark;
                d = 0, n = 0;
                cur = &n;
                mark = c=='+' ? 1 : -1;
            } else if (c == '/') {
                cur = &d;
            } else {
                *cur = *cur *10+c-'0';
            }
        }
        if (n) m[d] += n*mark;
        n = 0, d = 1;
        
        for (auto it = m.begin(); it != m.end(); ++it) {
            n = n*it->first + d*it->second;
            d *= it->first;
            if (!n) d=1;
            else {
                int k = abs(__gcd(n, d));
                n /= k;
                d /= k;
            }
        }
        return to_string(n)+"/"+to_string(d);
    }
};