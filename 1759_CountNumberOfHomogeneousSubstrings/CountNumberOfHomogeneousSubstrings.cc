class Solution {
public:
    int countHomogenous(string s) {
        int count = 1;
        int res = 0;
        for (int i=1;i<s.size();++i) {
            if (s[i] == s[i-1]) ++count;
            else {
                res += helper(count);
                res %= mod;
                count = 1;
            }
        }
        res += helper(count);
        res %= mod;
        return res;
    }
private:
    const int mod = 1e9+7;
    
    inline int helper(int n) {
        long res = ((long)n*(n+1)/2)%mod;
        return (int)res;
    }
};

// With more straightforward solution:

class Solution {
public:
    int countHomogenous(string s) {
        int res = 0;
        int count = 0;
        char pre = 0;
        for (char& c : s) {
            count = c == pre ? count+1 : 1;
            pre = c;
            res = (res+count)%mod;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
};