class Solution {
public:
    int newInteger(int n) {
        string s = "";
        while (n) {
            s.push_back(n%9+'0');
            n /= 9;
        }
        reverse(s.begin(), s.end());
        return stoi(s);
    }
};

// Another:

class Solution {
public:
    int newInteger(int n) {
        long base = 1, res = 0;
        while (n) {
            res += base*(n%9);
            n /= 9;
            base *= 10;
        }
        return res;
    }
};