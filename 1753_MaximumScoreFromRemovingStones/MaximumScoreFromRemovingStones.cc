class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        int res = 0;
        int k = min(s[0], s[2]-s[1]);
        res += k;
        s[0] -= k;
        s[2] -= k;
        k = s[0]/2;
        s[1] -= k;
        s[2] -= k;
        res += 2*k;
        return res + min(s[1], s[2]);
    }
};

// Better:

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int m = max(a, max(b,c));
        if (2*m > a+b+c) return a+b+c-m;
        return (a+b+c)/2;
    }
};