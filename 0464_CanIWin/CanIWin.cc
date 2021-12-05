class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal < 2) return true;
        int sum = maxChoosableInteger*(maxChoosableInteger+1)/2;
        if (sum < desiredTotal) return false;
        
        vector<int> m(1<<maxChoosableInteger, 0);
        return helper(maxChoosableInteger, desiredTotal, 0, m);
    }
private:
    bool helper(const int& n, int total, int bit, vector<int>& m) {
        if (total <= 0) return false;
        if (m[bit]) return m[bit] > 0;
        
        for (int i=0;i<n;++i) {
            if ((bit&(1<<i))==0 && !helper(n, total-i-1, bit|(1<<i), m)) {
                m[bit] = 1;
                return true;
            }
        }
        m[bit] = -1;
        return false;
    }
};