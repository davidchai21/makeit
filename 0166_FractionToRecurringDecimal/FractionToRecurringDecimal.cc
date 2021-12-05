class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if (!n) return "0";

        int mark = 1;
        uint64_t r = n;
        uint64_t dd = d;
        if (n < 0) {
            mark = -mark;
            r = n*(-1LL);
        }
        if (d < 0) {
            mark = -mark;
            dd = d*(-1LL);
        }
        
        string res = mark > 0 ? "" : "-";
        res += to_string(r/dd);
        r %= dd;
        if (r == 0) return res;
        res.push_back('.');
        
        unordered_map<int, int> m;
        while (r) {
            if (m.find(r) != m.end()) {
                res.insert(m[r], 1, '(');
                res.push_back(')');
                break;
            }
            m[r] = res.size();
            r *= 10;
            res += to_string(r/dd);
            r %= dd;
        }
        return res;
    }
};