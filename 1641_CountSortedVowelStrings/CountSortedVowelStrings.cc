class Solution {
public:
    int countVowelStrings(int n) {
        int res = 0;
        helper(0, res, n);
        return res;
    }
private:    
    void helper(int index, int& res, int sum) {
        if (index == 5) {
            if (!sum) {
                ++res;
            }
            return;
        }
        
        for (int j=0;j<=sum;++j) {
            helper(index+1, res, sum-j);
        }
    }
};

// Combination:

class Solution {
public:
    int countVowelStrings(int n) {
        int res = 5;
        if (n>1) res += helper(1, n-1)*10;
        if (n>2) res += helper(2, n-1)*10;
        if (n>3) res += helper(3, n-1)*5;
        if (n>4) res += helper(4, n-1);
        return res;
    }
private:
    int helper(int k, int n) {
        if (k > n/2) return helper(n-k, n);
        if (k==0) return 1;
        
        int res = 1;
        for (int i=1;i<=k;++i) {
            res *= n+1-i;
            res /= i;
        }
        return res;
    }
};

// Shorter Combination:

class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4)*(n+3)*(n+2)*(n+1)/24;
    }
};