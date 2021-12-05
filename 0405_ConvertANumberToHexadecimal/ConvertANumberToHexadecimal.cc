class Solution {
public:
    string toHex(int num) {
        if (!num) return "0";
        unsigned int n = num;
        string res = "";
        for (int i=0;i<8 && n;++i) {
            int c = 0;
            for (int i=0;i<4;++i) {
                c |= (n&1)<<i;
                n >>= 1;
            }
            if (c < 10) res.push_back(c+'0');
            else res.push_back('a'+c-10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Another:

class Solution {
public:
    string toHex(int num) {
        if (!num) return "0";
        
        const string book = "0123456789abcdef";
        unsigned int n = num;
        string res = "";
        for (int i=0;i<8 && n;++i) {
            res += book[n&0xf];
            n >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};