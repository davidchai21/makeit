class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;
        long t = 0L;
        int l = x;
        while (l) {
            t = t*10+(l%10);
            l /= 10;
        }
        return x==t;
    }
};

// Half-pass:

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || x%10==0 && x!=0) return false;
        int t = 0;
        while (x>t) {
            t = t*10+x%10;
            x /= 10;
        }
        return x == t || x == t/10;
    }
};